#include <stdio.h>
#define D 10
#define S 100
#define P 5
int order() {
  int t;
  do {
    scanf_s("%d", &t);
  } while (t < 1 || t>4);
  scanf_s("%*c");
  return t;
}
void Case1(char scan[][P], int N[], int h, int b) {
  int n = 0, i;
  for (i = 0; i < 4; i++) {
    scanf_s("%c", &(scan[h][i]));
    n *= 10;
    n += scan[h][i] - '0';
  }
  N[b] = n;
}
void Case2(char code[][P], char name[][D], int cost[], int dis[], char scan[][P], int h) {
  int y, i, j;
  for (j = 0; j < D; j++) {
    y = 1;
    for (i = 0; i < P - 1; i++) {
      if (code[j][i] != scan[h - 1][i]) {
        y = 0;
        break;
      }
    }
    if (y != 0) {
      for (i = 0; i < P - 1; i++) {
        printf("%c", code[j][i]);
      }
      printf(" ");
      for (i = 0; i < D; i++) {
        printf("%c", name[j][i]);
      }
      printf(" %d ", cost[j]);
      printf("%d%%\n", dis[j]);
      break;
    }
  }
}
void Case3(char scan[][P], char code[][P], char name[][D], int cost[],
  int dis[], int N[], float sum1, float sum2, int num[], int h) {
  int i, j, k, x, f, pro;
  for (k = 0; k < h; k++) {
    x = 1;
    for (j = 0; j < D; j++) {
      x = 1;
      for (i = 0; i < P - 1; i++) {
        if (code[j][i] != scan[k][i]) {
          x = 0;
          break;
        }
      }
      if (x != 0) {
        pro = 1;
        for (f = 0; f < k; f++) {
          if (N[f] == N[k]) {
            pro = 0;
            break;
          }
        }
        if (pro == 1) {
          for (i = 0; i < D; i++) {
            printf("%c", name[j][i]);
          }
          sum1 += cost[j];
          sum2 += 0.01f * dis[j] * cost[j];
          printf(" %d", cost[j]);
          printf(" %d", num[k]);
          printf(" %d\n", cost[j] * num[k]);
        }
        else {
          sum1 += cost[j];
          sum2 += 0.01f * dis[j] * cost[j];
        }
        break;
      }
    }
  }
  printf("Total amount = %.2f\n", sum1);
  printf("Total discount = %.2f\n", sum2);
  printf("Amount to be paid = %.2f\n", sum1 - sum2);
}
void Case4() {
  printf("Thank you for your purchase!");
}
void numbers(int N[], int num[], int h) {
  int i, j, u, x;
  for (i = 0; i < h; i++) {
    u = 0;
    for (j = 0; j < h; j++) {
      if (N[i] == N[j]) {
        u++;
      }
    }
    num[i] = u;
  }
}
void pri1(char code[][P], char name[][D], int cost[], int dis[]) {
  int i, j, k, f;
  for (i = 0; i < D; i++) {
    for (j = 0; j < P - 1; j++) {
      printf("%c", code[i][j]);
    }
    printf(" ");
    for (k = 0; k < D; k++) {
      printf("%c", name[i][k]);
    }
    printf(" %d", cost[i]);
    printf(" %d%%\n", dis[i]);
  }
  printf("\n");
  printf("Choose an order:\n");
  printf("1 - Scan the product\n");
  printf("2 - Display the scanned product\n");
  printf("3 - Generate a receipt and amount to be paid\n");
  printf("4 - Complete the purchase\n\n");
}
int main() {
  char name[D][D] = { "apples","peachs","oranges","melons","grape","bread","butter","pears","kiwi","lemons" };
  char code[D][P] = { "1607","0505","1498","2332","6752","1351","0064","2353","9437","1027" }, scan[S][P];
  int cost[D] = { 150,220,200,310,230,60,370,180,290,130 }, dis[D] = { 6,3,3,4,5,7,10,9,9,8 };
  int ord, fl = 1, h = 0, b = 0, num[S], N[S];
  float sum2 = 0.0f, sum1 = 0.0f;
  pri1(code, name, cost, dis);
  while (fl != 0) {
    ord = order();
    switch (ord) {
    case 1:
      Case1(scan, N, h, b);
      h++, b++;
      break;
    case 2:
      Case2(code, name, cost, dis, scan, h);
      break;
    case 3:
      numbers(N, num, h);
      Case3(scan, code, name, cost, dis, N, sum1, sum2, num, h);
      break;
    case 4:
      Case4();
      return 0;
    }
  }
  return 0;
}