#include <stdio.h>
#include <string.h>
#define AMOUNT (sizeof(product)/ sizeof(product[0]))
struct goods {
    const char* name;
    const char* description;
    double price;
    const char* barcodes;
    int discount;
};
struct goods product[]={
        {"cabbage", "This is an average head of an average cabbage", 54.99, "1613", 46},
        {"carrot", "A carrot. Just a carrot...", 9.99, "5144", 4},
        {"candies", "Sweet! Some candies!",89.99 ,"3134", 28},
        {"spaghetti", "Spaghetti italian",79.99 ,"4114", 8},
        {"zucchini", "Zucchini - schiacciata italian",49.99 ,"6613", 5},
        {"cheese", "Cheese, not cheese",239.99 ,"1117", 21},
        {"tomato", "Tomato is like an apple but better",14.99 ,"1335", 25},
        {"bacon", "Bacon - cool part of a cool pig",149.99 ,"0552", 2},
        {"lettuce", "Lettuce - when cabbage is not an option",29.99 ,"3333", 16},
        {"chicken", "Chicken... KFC...",199.99 ,"2015", 17},
        {"muffin", "Muffin - Delicious small piece of a cake",74.99 ,"4497", 16},
        {"pickles", "Pickles are just forgotten cucumbers in a jar...",319.99 ,"2395", 14},
        {"mushroom", "Mushroom - \"it's me, Mario!\"", 29.99, "0000", 38},
};
int products[AMOUNT] = {0};

double cost = 0;
double cost_without_discounts = 0;
void rules(){
    printf ("All items scaned automatically\n");
    printf("c - print check\n");
    printf("f - sum up and show final cost\n");
    printf("All barcodes:\n");
    for (int i = 0; i < AMOUNT; i++) {
        printf(product[i].name);
        printf(": ");
        printf(product[i].barcodes);
        printf("\n");
    }
    printf("\n");
}
int find_barcodes(char* barcodes){
    for (int i=0; i<AMOUNT; i++)
        if (!strcmp(barcodes, product[i].barcodes))
            return i;
    return -1;
}

void add(int index){
    printf(product[index].description);
    do
    {
        char confirm[2];

        printf("\nBuy one (Yes/No)? ");
        fgets(confirm, sizeof(confirm), stdin);
        fseek(stdin, 0, SEEK_END);

        switch(confirm[0])
        {
            case '\n':
                printf("Yes\n");
            case 'y':
            case 'Y':
                products[index]++;
                printf("Added\n");
                break;
            case 'n':
            case 'N':
                printf("Done\n");
                return;
        }

    } while (1);
}
void make_check(){
    cost_without_discounts = 0;
    cost = 0;
    char buffer[80];
    int i;
    printf("\n");
    snprintf(buffer, sizeof(buffer),
             "\n %-20s %8s %5s %9s\n",
             "Name", "Price", "Count", "Total");
    printf(buffer);
    printf("\n");
    for (int i = 0; i < AMOUNT; i++)
    {

        if (products[i] > 0) {
            snprintf(buffer, sizeof(buffer),
                     " %-20s %8.2lf %4d %9.2lf\n",
                     product[i].name,
                     product[i].price,
                     products[i],
                     (double)products[i] * product[i].price);
            printf(buffer);
            cost_without_discounts += (double)products[i] * product[i].price;
            cost += (double)products[i] * product[i].price * (1.0 - ((double)(product[i].discount))/100);
        }
    }
    printf("\n");
    printf("Cost without discount: ");
    printf("%.2lf\n\n", cost_without_discounts);
}
void fin_cost(){
    make_check();
    printf("Discount: ");
    printf("%.2f", cost_without_discounts - cost);
    printf("\nTotal price: ");
    printf("%.2f", cost);
}
int move(){
    char scan[5];

    fgets(scan, sizeof(scan), stdin);
    fseek(stdin, 0, SEEK_END);
    switch(scan[0]){
        case 'f':
            fin_cost();
            return -1;
        case 'c':
            make_check();
            break;
        default:{
            int index=find_barcodes(scan);
            if (index<0)
                printf("Couldn't find this barcode");
            else add(index);
        }

    }
    return 0;

}

int main(){
    rules();
    while(!move());
}