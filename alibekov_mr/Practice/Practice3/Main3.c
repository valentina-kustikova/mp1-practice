#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main() 
 {
  int PC_igraet = -1, x, i = 0, x_igroka, a = 1, b = 1000, t = 1, RetryGame = 0, GameHonestly = -1;
  char znak;

  do 
   {
    printf("Who generate number?    1 - PC.    0 - User\n");
    scanf_s("%d", &PC_igraet);
    if (PC_igraet == 1) {
    printf("Do you want to play honestly?     1 - Yes.       0 - No\n");
    scanf_s("%d", &GameHonestly);
   }

  srand((unsigned int)time(0));
  x = 999.0 / RAND_MAX * rand() + 1;

  while (PC_igraet == 1) 
   {
    i++;
    if (GameHonestly == 0) printf("%d\n", x);
    printf("Enter your number.\n");
    do 
     {
      scanf_s("%d", &x_igroka);
     } while ((x_igroka <= 1) || (x_igroka >= 1000));
    if (x_igroka == x) 
     {
     printf("You win\nYour number = %d. ", x);
     i == 1 ? printf("Win in 1 step.\n") : printf("Win in %d steps. \n", i);
     PC_igraet = -1;
     }
    if (x_igroka < x) printf("My number > Your number\n");
    if (x_igroka > x) printf("My number < Your number\n");
   };

   while (PC_igraet == 0) 
    {
     i++;
     if (t != 0) 
      {
       printf("Enter your number.\nYour number: ");
       do 
        {
         scanf_s("%d", &x_igroka);
        } while ((x_igroka < 1) || (x_igroka > 1000));
       t = 0;
      }		
     x = 1.0 * (b - a) / RAND_MAX * rand() + a;
     printf("My number: %d\n", x);		
     printf("Enter '>' if your number > than my number.\n"); 
     printf("Enter '<' if your number < than my number.\n");
     printf("Enter '=' if your number = my number.\n");
     do 
      {   
       scanf_s("%c", &znak);
      } while ((znak != '>') && (znak != '<') && (znak != '='));
      switch (znak) 
       {
        case '<': b = x;
                  break;	
        case '>': a = x;
                  break;	
        case '=': printf("I win.\nYour number = %d. ", x);    
                  i == 1 ? printf("Win in 1 step.\n") : printf("Win in %d steps.\n", i);
                  PC_igraet = -1;
                  break;
       }	
    };	

   printf("Retry?        1 - Yes.     0 - No\n");	
   scanf_s("%d", &RetryGame);
  } while (RetryGame == 1);
}