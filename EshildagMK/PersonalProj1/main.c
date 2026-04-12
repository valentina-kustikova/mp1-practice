#include "operations.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
	int usernum, pnom_choice;
	pnom_info first_pnom;
	pnom_info second_pnom;
	char* pnom_filename = "pnom_info.txt";
	get_info(&first_pnom, &second_pnom, pnom_filename);
	printf("=============\n");
	printf("1st polynom:\n");
	printer(&first_pnom);
	printf("2nd polynom:\n");
	printer(&second_pnom);
	printf("=============\n");

	sum(&first_pnom, &second_pnom);
	subtract(&first_pnom, &second_pnom);
	multiply(&first_pnom, &second_pnom);
	printf("1st polynom:\n");
	diff_pnom(&first_pnom);
	printf("2nd polynom:\n");
	diff_pnom(&second_pnom);
	printf("***************\n");
	printf("\nEnter your NUM: ");
	scanf_s("%d", &usernum);
	printf("\nEnter choosen POLYNOM: ");
	scanf_s("%d", &pnom_choice);
	switch (pnom_choice) {
	case 1: calculate(&first_pnom, usernum); printf("***************\n"); break;
	case 2: calculate(&second_pnom, usernum); printf("***************\n"); break;
	default: printf("Error. Only 2 polynoms exist"); break;
	}
}
