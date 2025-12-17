#include <stdio.h>
#include <string.h>
#define brange 4

int bd(char code[5], char tp[][30], int chk[]);

void printer(char tp[3][30]) {
    printf("name: %s cost: %s\n", tp[1], tp[2]);
}

int main() {
    char tp[4][30];
    int sum = 0, i = 0, u = 0;
    int chek[brange] = { 0, 0, 0, 0 };
    char codes[brange][5] = { "0001", "0002", "0003", "0004" };

    while (1) {
        char inp[10];
        fgets(inp, sizeof(inp), stdin);
        inp[strcspn(inp, "\n")] = 0;

        if (strcmp(inp, "end") == 0) {
            break;
        }
        else {
            sum += bd(inp, tp, chek);
            printer(tp);
            
        }
    }
    printf("calculating your personal discounts...\n");
    for (i = 0; i < brange; i++) {
        if (chek[i] > 0) {
            int c = chek[i];
            int g = c * bd(codes[i], tp, chek);
            printf("name: %s cost: %s X %d = %d with a %s %% discount\n", tp[1], tp[2], c, g, tp[3]);
        }

    }
    printf("total: %d\n", sum);
    return 0;
}

int bd(char code[5], char tp[][30], int chk[]) {
    char codes[brange][5] = { "0001", "0002", "0003", "0004" };
    char names[brange][30] = { "milk", "bread", "bun", "salt" };
    char costs[brange][30] = { "100", "30", "10", "20" };
    char sales[brange][30] = { "10", "0", "15", "50" };
    int icosts[brange] = { 90, 30, 10, 10 };

    int k = -1;
    for (int i = 0; i < brange; i++) {
        if (strcmp(code, codes[i]) == 0) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        strcpy(tp[0], "not found");
        strcpy(tp[1], "not found");
        strcpy(tp[2], "not found");
        strcpy(tp[3], "not found");
        return 0;
    }

    strcpy(tp[0], codes[k]);
    strcpy(tp[1], names[k]);
    strcpy(tp[2], costs[k]);
    strcpy(tp[3], sales[k]);
    chk[k]++;
    return icosts[k];
}