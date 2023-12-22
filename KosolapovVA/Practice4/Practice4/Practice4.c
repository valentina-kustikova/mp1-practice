#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 255
#define m 4
#define N 10

char* name[N] = { "Milk","Bread","Sausage","Cheese", 
"Flakes", "Fish fillet", "Pasta", "Sugar", "Juice", "Chocolate" };
double price[N] = { 99.9, 25.9, 189.9, 399.9, 199.9, 
349.9, 139.9, 95.9, 119.9, 99.9 };
char* barcode[N] = { "1031","2041", "3051","1161","4071",
                     "3181","2191","5012","6022","7032"};
double discount[N] = {10.0, 5.0, 20.0, 3.0, 1.0, 8.0, 25.0, 4.0, 50.0, 30.0};
char* Const_E1 = "Enter 1 if you want to scan the next item.\n";
char* Const_E2 = "Enter 2 if you want to see the product description.\n";
char* Const_E3 = "Enter 3 if you want to add product details to the receipt.\n";
char* Const_E4 = "Enter 4 if you want to withdraw the receipt.\n";
char* Const_E5 = "Enter 5 if you want to withdraw the sum.\n";
int operation = 1;

void struct_craft(int i);
char* scan_barcode();
void check_barcode(char* u_bar, int *f_id);
void inf_output(int id);
void sum_counting(int id);
void print_receipt();
double sum_receipt(int i);
void choice_operation(int* oper);

struct receipt
{
    char* name;
    double price;
    int count;
    double discount;
    double sum;
}pos[N];

int main()
{
    char* user_barcode;
    int  id, i = 0;
    struct_craft(i);
    do {
        switch (operation) 
        {
        case 1:
            user_barcode = scan_barcode();
            check_barcode(user_barcode, &(id));
            if (id == -1)
            {
                printf("Error, this product is not in the database,try again\n");
            }
            else
            {
                printf("%s%s%s%s%s", Const_E1, Const_E2, Const_E3, Const_E4, Const_E5);
                choice_operation(&operation);
            }
            break;
        case 2:
            inf_output(id);
            break;
        case 3:
            sum_counting(id);
            break;
        case 4:
            print_receipt();
            break;
        }
    } while (operation != 5);    
    printf("Sum receipt = %g", sum_receipt(i));
    return 0;
}
void struct_craft(int i)
{
    for (; i < N; i++)
    {
        pos[i].name = name[i];
        pos[i].price = price[i];
        pos[i].count = 0;
        pos[i].discount = discount[i];
        pos[i].sum = 0;
    }
}
char* scan_barcode()
{
    char u_bar[MAX_LEN];
    printf("Please scan the 4 digit barcode:");
    scanf("%s", &u_bar);
    while ((strlen(u_bar)) != 4)
    {
        if ((strlen(u_bar)) > 4)
        {
            printf("Error, your barcode is too long, scan again:");
        }
        if ((strlen(u_bar)) < 4)
        {
            printf("Error, your barcode is too short, scan again:");
        }
        scanf("%s", &u_bar);
    }
    return (u_bar);
}
void check_barcode(char* u_bar, int *f_id)
{    
    *f_id = -1;
    int i = 0;
    for (; i < N; i++)
    {
        if (strcmp(u_bar, barcode[i])==0)
        {
            *f_id = i;\
            break;
        }
    }
}
void inf_output(int id)
{
    printf("Name:%s, price:%g, discount:%g \n", name[id], price[id], discount[id]);
    printf("%s%s%s%s", Const_E1, Const_E3, Const_E4, Const_E5);
    choice_operation(&operation);
}
void sum_counting(int id)
{
    int count_t=0;
    printf("How many pieces do you want to add to the receipt?\n");
    scanf("%d", &(count_t));
    pos[id].count=count_t+ pos[id].count;
    pos[id].sum = (pos[id].price - (pos[id].price * pos[id].discount / 100.0)) * pos[id].count;
    printf("%s%s%s", Const_E1, Const_E4, Const_E5);
    choice_operation(&operation);
}
void print_receipt()
{
    int i = 0;
    for (; i < N; i++)
    {
        if (pos[i].count != 0)
        {
            printf("Name:%s,Price=%g,", pos[i].name, pos[i].price);
            printf("Count:%d, Discount=%g, Sum=%g\n", pos[i].count, pos[i].discount, pos[i].sum);
        }
    }
    printf("%s%s", Const_E1, Const_E5);
    choice_operation(&operation);
}
double sum_receipt(int i)
{
    double sum = 0;
    for (; i < N; i++)
    {        
        sum = (sum + pos[i].sum);
    }
    return sum;
}
void choice_operation(int *oper)
{
    int flag = -1;
    do
    {
        int temp;
        scanf("%d", &temp);
        if ((temp >= 0) && (temp <= 5))
        {
            flag = 0;
            *oper = temp;
        }
        else
        {
            printf("Incorrect operation, please enter again.\n");
        }
    } while (flag == -1);
}
