#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


int main()
{
    int i = 0;
    TVector vector;
    TVector* vector_dynamic, * v1, * v2, * res;
    float res_dotprod;

    allocate_vector(&v1, 9);
    allocate_vector(&v2, 9);
    fill_vector(v1);
    fill_vector(v2);

    printf("select action with matrix 1 - matrix '+' matrix // 2 - matrix '+' const // 3 - matrix '*' matrix // 4 - matrix '*' const");

    int select = 0;
    scanf_s("%d", &select);

    if (select == 1) {
        res = add_vector(v1, v2);
        print_vector(res);
        free_vector(&res);
    }

    if (select == 2) {
        res = add_const(v1, 1.0f);
        print_vector(res);
        free_vector(&res);
    }
    
    if (select == 3){
        res_dotprod = multi_vector(v1, v2);
        printf("%f\n", res_dotprod);
    }
    
    if (select == 4) {
        res = multi_const(v1, 2.0f);
        print_vector(res);
        free_vector(&res);
    }
    

    

    free_vector(&v1);
    free_vector(&v2);
    return 0;
}
