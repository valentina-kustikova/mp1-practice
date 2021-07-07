#include <stdio.h> 
#define N 9 
int Product(int barcode[], int number[], int p)
{
    int i;
    if ((barcode[p]>=0)&&(barcode[p]<=8))
    {
        printf("Barcode(from 0 ro 8)\n");
        scanf("%d", &barcode[p]);
        printf("\nNumber\n");
        scanf("%d", &i); 
        return i; 
    }
    else 
        printf("\nThis barcode doesn't exist\n");
}
void ProductDescription(char name[][10], int price[], int productdiscount[], int i)
{
    int j;
    for(j = 0; j < 10; j++)
    {
        printf("%c", name[i][j]);
    }
    printf("\nPrice: %d\n", price[i]);
	printf("Discount of product: %d\n", productdiscount[i]);
}    
void AddToBasket (int number[], int x, int y)
{
    number[x] += y;
    printf("(added)\n");
}
void Check(char name[][10], int price[], int productdiscount[], int number[])
{
    int pr = 0, fin = 0, t, i;
    for(i = 0; i < N; i++)
    {
        if (number[i] > 0)
        {
            ProductDescription(name, price, productdiscount, i);
            printf("\nNumber: %d", number[i]);
            pr = pr + number[i] * price[i];
            fin = fin +(price[i] * ((100 - productdiscount[i]) * number[i])/100);
        }
    }
    t= (pr-fin)*100/pr;
    printf("\n=======================================");
    printf("\n==============SWEET  SHOP==============");
    printf("\n=======================================");
    printf("\n======================check ¹0380======");
	printf("\n======================27.11.2018=12:57=");
    printf("\n Price: %d rub\n Price with discount: %d rub\n Total discount: %d %\n", pr,fin,t);
	printf("\n======THANK YOU FOR YOUR PURCHASE======");
	printf("\n=======================================");
    
}
void main ()
{
    char name[N][10] = {"Kinder   ", "Snickers ", "Mars     ", "Twix     ", "Milky Way","Baunty   ", "Choco Pie", "Haribo   ", "Skittles "};
    int price[N] = {80, 50, 45, 55, 35, 40, 38, 60, 58};
    int productdiscount[N] = {10, 15, 20, 25, 30, 35, 40, 45, 50};
    int number[N] = {0};
    int barcode[10];
    int s, p = 0, num;
    num=(barcode, number, p);
    while(p!= 4)
    {  
        printf("\nChoose the comand:\n1 - To scan barcode\n2 - To see the description\n3 - To add to the bascket\n4 - To make a check \n");
        scanf("%d", &s);
        switch(s)
        {
            case 1:
                num = Product(barcode, number, p);
                break;
            case 2:
                ProductDescription(name, price, productdiscount, barcode[p]);
                break;
            case 3:
                AddToBasket(number, barcode[p], num);
                p++;
                break;
            case 4:
                Check(name, price, productdiscount, number);
                break;
        }
    }
    
}