#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define LINE 512
#define ENTRY_SIZE 1000

struct product {
    const char* barcode;
    const char* name;
    int price;
    int discount;
};

struct entry {
    struct product product;
    int amount, cost;
};

struct check {
    struct entry* entries;
    int count;
    int cost, discount;
    int total;
};

struct product products[] = {
  {.barcode = "0000", .name = "Apple", .price = 20, .discount = 5},
  {.barcode = "0001", .name = "Banana", .price = 50, .discount = 2}
};
int products_amount = sizeof(products) / sizeof(struct product);

int scan_new_product(struct product *product);
void view_product_info(struct product product);
void add_products(struct product product, int amount, struct check *check);
int count_cost(struct check check);
int count_discount(struct check check);
void print_check(struct check check);

int main() {
    char query[LINE];
    bool has_scanned = false;
    bool has_check = false;
    struct product scanned_product;
    struct entry entry_list[ENTRY_SIZE], final_entry_list[ENTRY_SIZE];
    struct check check = (struct check){
        .entries = entry_list,
        .count = 0,
        .cost = 0, .discount = 0,
        .total = 0
    };
    struct check final_check;
    while (true) {
        int i;
        printf("> ");
        scanf("%s", query);
        scanf("%*[^\n]");
        for (i = 0; query[i]; i++)
            query[i] = tolower(query[i]);

        if (!strncmp(query, "help", 4)) {
            printf("Available commands:\n"
                "HELP - prints out this command list\n"
                "SCAN [barcode] - scans a new product\n"
                "VIEW - prints information about a recently scanned product\n"
                "ADD [amount] - adds [amount] scanned products to the check\n"
                "CHECK - forms a check\n"
                "TOTAL - prints out the formed check\n"
                "QUIT - quits the program\n");
        }
        else if (!strncmp(query, "scan", 4)) {
            has_scanned = (scan_new_product(&scanned_product) == 0);
        }
        else if (!strncmp(query, "view", 4)) {
            if (has_scanned) {
                view_product_info(scanned_product);
            }
            else {
                printf("Scan a product first.\n");
            }
        }
        else if (!strncmp(query, "add", 3)) {
            if (has_scanned) {
                int amount;
                if (scanf("%d", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount.\n");
                    continue;
                }
                add_products(scanned_product, amount, &check);
            }
            else {
                printf("Scan a product first.\n");
            }
        }
        else if (!strncmp(query, "check", 5)) {
            for (i = 0; i < check.count; i++) {
                final_entry_list[i] = entry_list[i];
            }

            final_check = (struct check){
              .entries = final_entry_list,
              .count = check.count,
              .cost = count_cost(check),
              .discount = count_discount(check)
            };
            
            has_check = true;
            printf("Check formed. Use TOTAL to print it out.\n");
        }
        else if (!strncmp(query, "total", 5)) {
            if (has_check) {
                print_check(final_check);
            }
            else {
                printf("Check has not been formed yet. Use CHECK.\n");
            }
        }
        else if (!strncmp(query, "quit", 4)) {
            break;
        }
        else {
            printf("Unknown command. Use HELP to view command list.\n");
        }
    }
    return 0;
}

int scan_new_product(struct product *product) {
    int i;
    char barcode[LINE];
    scanf("%s", barcode);
    if (strlen(barcode) != 4) {
        printf("Invalid barcode length.\n");
        return 1;
    }

    for (i = 0; i < products_amount; i++) {
        if (!strncmp(barcode, products[i].barcode, 4)) {
            *product = products[i];
            printf("Product %s - %s scanned.\n", product->barcode, product->name);
            return 0;
        }
    }
    
    printf("Product with this barcode was not found.\n");
    return 1;
}

void view_product_info(struct product scanned) {
    printf("Barcode: %s\nName: %s\nPrice per item: %d\nDiscount: %d%%\n",
        scanned.barcode, scanned.name, scanned.price, scanned.discount);
}

void add_products(struct product product, int amount, struct check* check) {
    int i;
    struct entry* entry_list = check->entries;
    bool found = false;
    
    for (i = 0; i < check->count; i++) {
        if (!strncmp(product.barcode, entry_list[i].product.barcode, 4)) {
            entry_list[i].amount += amount;
            entry_list[i].cost += amount * product.price;
            found = true;
            printf("Product %s - %s (amount - %d) added to the check.\n",
                product.barcode, product.name, amount);
            return;
        }
    }

    if (check->count < ENTRY_SIZE) {
        entry_list[check->count++] = (struct entry){
            .product = product,
            .amount = amount,
            .cost = amount * product.price
        };
        printf("Product %s - %s (amount - %d) added to the check.\n",
            product.barcode, product.name, amount);
    }
    else {
        printf("Too many entries! (1000)\n");
    }
}

int count_cost(struct check check) {
    int cost = 0, i;
    for (i = 0; i < check.count; i++)
        cost += check.entries[i].cost;
    return cost;
}

int count_discount(struct check check) {
    int discount = 0, i;
    for (i = 0; i < check.count; i++) {
        struct product p = check.entries[i].product;
        discount += check.entries[i].amount * p.price * p.discount / 100;
    }
    return discount;
}

void print_check(struct check check) {
    int i;
    for (i = 0; i < check.count; i++) {
        struct entry entry = check.entries[i];
        struct product p = entry.product;
        printf("%s - %s - %d - %d\n",
            p.barcode, p.name, entry.amount, entry.cost);
    }
    printf("-----------------\n");
    printf("COST: %d\nDISCOUNT: %d\nTOTAL: %d\n",
        check.cost, check.discount, check.cost - check.discount);
}