#include<stdio.h>               
#include<stdlib.h>				
#include<time.h>				
#include<stdbool.h>
#define N 10				
void main()
{
  int  new_game = 1, p, i = 0, j = 0, steps = 0, n, b = 0, k = 0, honestly_game;
  long long x_igroka, x = 0, x_forChanges, x_igroka_forChanges, min = 1, max;
  short cells_x[10] = { 0 }, cells_x_igroka[10] = { 0 };
  _Bool GameOver = false, xIsGood = true, x_igrokaIsGood = true, ThereIs0 = false, GameIsHonest = false;
  long long number_x[N] = { 0 };

  printf("Hello. This is game %cBulls and Cows%c.\n", '"', '"');
  printf("Do you want to play?             1 - yes.       0 - no.\n");
  scanf_s("%d", &new_game);
  if (new_game == 0) GameOver = true;
  if (new_game == 1) GameOver = false;
 
  while (!GameOver)
  {
    printf("Do you want to play honestly?             1 - yes.     0 - no.\n");
    scanf_s("%d", &honestly_game);
    if (honestly_game == 1) GameIsHonest = true;
 
    do
    {
      printf("Enter n (length of number).\n");
      scanf_s("%d", &n);
    } while ((n <= 0) || (n > 10));
 
    for (i = 1; i < n; i++)  min *= 10;
    max = min * 10;
 
 
    printf("Number is generating. Please wait...\n");
    i = 0;
    xIsGood = true;
    while (i < n)
    {
      do
      {
        xIsGood = true;
        srand((unsigned int)time(0));
        number_x[i] = rand() % 10;
        if ((i != 9) && (number_x[i] == 0)) ThereIs0 = true;
        for (j = 0; j < i; j++) 
        {
          if ((number_x[i] == number_x[j]) || ((i == (n - 1)) && (number_x[i] == 0)))
          {
            if ((n == 10) && (number_x[i] == 0) && (i == 9) && (!ThereIs0))
            {
              i = 7;
              ThereIs0 = false;
            }
            number_x[i] = 0;
            xIsGood = false;
            break;
          };
        }
      } while (!xIsGood);
      i++;
    }

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < i; j++)
      {
        number_x[i] *= 10;
      }
    }

    for (i = 0; i < n; i++)
    {
      x += number_x[i];
    }

    x_forChanges = x;
    for (i = 0; i < n; i++)
    {
      cells_x[x_forChanges % 10] = i + 1;
      x_forChanges /= 10;
    }
    printf("Number generated.\n");
    do
    {
      steps++;
      do
      {
        if (!GameIsHonest) printf("%lli\n", x);
        printf("Enter number.\n");
        scanf_s("%lli", &x_igroka);
        x_igroka_forChanges = x_igroka;
        for (i = 0; i < n; i++)
        {
          if ((cells_x_igroka[x_igroka_forChanges % 10] == 0) && (x_igroka >= min) && (x_igroka < max))
          {
            cells_x_igroka[x_igroka_forChanges % 10] = i + 1;
            x_igrokaIsGood = true;
            x_igroka_forChanges /= 10;
          }
          else
          {
          printf("You entered bad number.\n");
          steps++;
          x_igrokaIsGood = false;
          for (p = 0; p < N; p++)
          {
          cells_x_igroka[p] = 0;
          }
          break;
          }
        }
      } while (!x_igrokaIsGood);
    
      for (i = 0; i < N; i++)
      {
        if ((cells_x[i] != 0) && (cells_x_igroka[i] != 0)) cells_x[i] == cells_x_igroka[i] ? b++ : k++;
      }

      if (b != n) printf("Number of bulls: %d\nNumber of cows: %d\n", b, k);
      else
      {
        printf("\n\nYou win!\nMy number is %lli\n", x);
        steps == 1 ? printf("Win in 1 step. \n") : printf("Win in %d steps. \n", steps);
        printf("Do you want to play again?      1 - yes.       0 - no.\n");
        scanf_s("%d", &new_game);
        if (new_game == 0) GameOver = true;
        break;
      }
      b = 0;
      k = 0;
      x_igroka = 0;
      x_igroka_forChanges = 0;
      for (p = 0; p <N; p++)
    {
      cells_x_igroka[p] = 0;
    }

    } while (b != n);
    for (p = 0; p <N; p++)
    {
      cells_x[p] = 0;
    }
    for (p = 0; p <N; p++)
    {
      cells_x_igroka[p] = 0;
    }
    GameIsHonest = false;
    honestly_game = 0;
    x = 0;
    x_forChanges = 0;
    n = 0;
    b = 0;
    k = 0;
    min = 1;
    max = 1;
    x_igroka = 0;
    x_igroka_forChanges = 0;
    for (p = 0; p <N; p++)
    {
      cells_x[p] = 0;
    }
    for (p = 0; p <N; p++) 
    {
      number_x[p] = 0;
    }
    steps = 0;
  }
}