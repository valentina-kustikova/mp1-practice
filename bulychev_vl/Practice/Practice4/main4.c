#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define kollvo_product 10
#define length_titles 10

char name_product[kollvo_product + 1][length_titles] = {"", "Bread", "Flakes", "Cabbage", "Carrot", "Potato", "Milk", "Sausage", "Eggs", "Tea", "Coffee"};
int discount_product[kollvo_product + 1];
int f = 0;
int kol[kollvo_product + 1];

void product(int id)
{
    int i;
    for (i = 0; i < length_titles; i++)
    {
        printf("%c", name_product[id][i]);
        f = 1;
    }
}

void discount(int min_skidka, int max_skidka)
{
    int i;
    srand((unsigned int) time(0));
    discount_product[0] = 0;
    for (i = 1; i < kollvo_product + 1 + 1; i++)
    {
        discount_product[i] = min_skidka + rand() % (max_skidka - min_skidka);
    }
}

void menu()
{
    printf("--------------------- \n");
    printf("Menu:\n");
    printf("1- Scan product \n");
    printf("2- Add product to check \n");
    printf("3- Check \n");
    printf("4- To pay \n");
    printf("0- Close programm \n");
    printf("--------------------- \n");
}

void main()
{
    int menu_1;
    int code = 0;
    int i = 0;
    long prices[kollvo_product + 1 ] = {30, 80, 20, 20, 15, 30, 30, 40, 30, 50};
    long sum = 0;
    discount(1,50);

    menu();
    do 
    {
        if (f == 1)
        {
            menu();
        }
        printf("Your choice = ");
        scanf("%d", &menu_1);
        switch (menu_1) 
        {
        case 1:
            printf("-1- \n"); 
            scanf("%d", &code);
            product(code);
            if (f == 1)
            {
                printf("\nPrice without discount - %d.\n", prices[code]);
                printf("Product discount - %d percent.\n", discount_product[code]);
            }
            break;
        case 2:
            if (code == 0)
            {
                printf("Product is not scanned. \n");
                f = 1;
            }
            else
            {
                kol[code]++;
                printf("Product added to check \n");
                sum += (prices[code] - (prices[code] * discount_product[code] * 0.01));
            }
            break;
        case 3:
            if (code == 0)
            {
                printf("Product is not scanned. \n");
                f = 1;
            }
            else
                for (i = 0; i < kollvo_product; i++)
                    if (kol[i] != 0)
                {
                    product(i);
                    printf("\nPrice without discount - %d.\n", prices[i]);
                    printf("Number of such products - %d.\n", kol[i]);
                    printf("Total price without discount - %d.\n", (kol[i] * prices[i]));
                    printf("Product discount - %d percent.\n", discount_product[i]);
                }
            break;
        case 4:
            if (code == 0)
            {
                printf("Product is not scanned. \n");
                f = 1;
            }
            else
                printf("To pay - %d.\n", sum);
            break;
        case 0:
            return;
        default:
            printf("!!!Wrong!!!\n");
        }
    } while (1);
} 