#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int price[9999], sale[9999], basket[9999] = { 0 };  
int f;
int i;
char name[9998][10];
long total_price, total_sale;
int id;
char c;

void gen_arr(int a[],int n,int min,int max)
{
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % max + min;
    }
}

void fill_name()
{
    name[10][0] = 'd';
    name[10][1] = 'o';
    name[10][2] = 'o';
    name[10][3] = 'r';

    name[20][0] = 'c';
    name[20][1] = 'u';
    name[20][2] = 'r';
    name[20][3] = 't';
    name[20][4] = 'a';
    name[20][5] = 'i';
    name[20][6] = 'n';
    name[20][7] = 's';

    name[30][0] = 'm';
    name[30][1] = 'i';
    name[30][2] = 'r';
    name[30][3] = 'r';
    name[30][4] = 'o';
    name[30][5] = 'r';

    name[40][0] = 'h';
    name[40][1] = 'a';
    name[40][2] = 'n';
    name[40][3] = 'g';
    name[40][4] = 'e';
    name[40][5] = 'r';

    name[50][0] = 'w';
    name[50][1] = 'a';
    name[50][2] = 'r';
    name[50][3] = 'd';
    name[50][4] = 'r';
    name[50][5] = 'o';
    name[50][6] = 'b';
    name[50][7] = 'e';

    name[60][0] = 'c';
    name[60][1] = 'a';
    name[60][2] = 'r';
    name[60][3] = 'p';
    name[60][4] = 'e';
    name[60][5] = 't';

    name[70][0] = 'c';
    name[70][1] = 'h';
    name[70][2] = 'a';
    name[70][3] = 'i';
    name[70][4] = 'r';

    name[80][0] = 'a';
    name[80][1] = 'r';
    name[80][2] = 'm';
    name[80][3] = 'c';
    name[80][4] = 'h';
    name[80][5] = 'a';
    name[80][6] = 'i';
    name[80][7] = 'r';

    name[90][0] = 's';
    name[90][1] = 'o';
    name[90][2] = 'f';
    name[90][3] = 'a';

    name[100][0] = 't';
    name[100][1] = 'a';
    name[100][2] = 'b';
    name[100][3] = 'l';
    name[100][4] = 'e';
}

void get_name(int id)
{
    f = 0;
    if ((id != 10) && (id != 20) && (id != 30) && (id != 40) && (id != 50) &&
        (id != 60) && (id != 70) && (id != 80) && (id != 90) && (id != 100))
    {
        printf("The goods with the bar code is not in the store\n");
    }
        
    else
    {
        printf("Name of the goods:");
        for (i = 0; i < 10; i++)
            printf("%c", name[id][i]);
        printf("\n");
        f = 1;
    }
}


void main()
{
    total_price = 0, total_sale = 0;
    i = 0, id = 0;
    gen_arr(price, 9998, 1, 1000);    //Generate price
    gen_arr(sale, 9998, 1, 50);       //Generate discount
    fill_name();
   
    
    printf("Cashbox\n");
    printf("Enter number, corresponding of desired command \n");
    printf("1 - To scan the product\n");
    printf("2 - To print the description of the scanned product\n");
    printf("3 - To add product data to check\n");
    printf("4 - To generate check for purchase\n");
    printf("5 - To generate the total amount to be paid\n");
    
    do
    {
        scanf("%c", &c);
        switch(c)
        {
            case '1':
                printf("Enter bar code of product\n");
                scanf("%d", &id);
                break;

            case '2':
                if (id == 0)
                {
                    printf("Scan the product to get a description\n");
                }
                else
                {
                    get_name(id);
                    if (f == 1)
                    {
                    printf("Price without discount = %d rub.\nDiscount = %d%%,\n", price[id], sale[id]);
                    printf("Price with discount = %f rub.\n", price[id] * (1 - (sale[id] / 100.0f)));
                    }
                }
                break;
            case '3':
                if (id == 0)
                    printf("Scan the product to add it to the check\n");
                else 
                    basket[id]++;     
                break;
            case '4':
                printf("Check:\n");
                for (i = 0; i < 9998; i++)
                {
                    if (basket[i] != 0)
                    {
                        get_name(i);
                        printf("The price for unit = %d rub.\n", price[i]);
                        printf("Quantity of goods = %d pieces\n", basket[i]);
                        printf("Total cost per item = %d rub.\n", price[i] * basket[i]);
                        total_price += price[i];
                        total_sale += price[i] * (float)(sale[i] / 100.00);
                    }
                } 
                printf("Total cost = %ld\n", total_price);
                printf("Total discount = %ld\n", total_sale);
                printf("In total = %ld\n", total_price - total_sale);

                break;

            case '5':
                printf("In total = %ld\n", total_price - total_sale);  
                break;             
        }
    }while(1);
}