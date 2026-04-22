#include "operations.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	int pnom_choice, math_choice, flag;
	double usernum;
	flag = 1;
	pnom_info first_pnom;
	pnom_info second_pnom;
	pnom_info res_pnom;

	char* pnom_filename;
	if (argc < 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	pnom_filename = argv[1];

	get_info(&first_pnom, &second_pnom, pnom_filename);
	printf("=============\n");
	printf("1st polynom:\n");
	printer(&first_pnom);
	printf("2nd polynom:\n");
	printer(&second_pnom);
	printf("=============\n");

	do {
		printf("MENU:\n");
		printf("1 - SUM\n");
		printf("2- SUBSTRACT\n");
		printf("3 - MULTYPLY\n");
		printf("4 - DIFF\n");
		printf("5 - CALCULATE\n");
		printf("0 - EXIT\n");
		printf("Choose:\n");
		scanf("%d", &math_choice);
		switch (math_choice)
		{
		case 0: return 0;
		case 1: 
			sum(&first_pnom, &second_pnom, &res_pnom);
			printer(&res_pnom);
			free_polynomial(&res_pnom);
			break;
		case 2:
			subtract(&first_pnom, &second_pnom, &res_pnom);
			printer(&res_pnom);
			free_polynomial(&res_pnom);
			break;
		case 3:
			multiply(&first_pnom, &second_pnom, &res_pnom);
			printer(&res_pnom);
			free_polynomial(&res_pnom);
			break;
		case 4:
			printf("Choose pnom:");
			scanf_s("%d", &pnom_choice);
			switch (pnom_choice) {
			case 1:
				diff_pnom(&first_pnom, &res_pnom);
				printer(&res_pnom);
				free_polynomial(&res_pnom);
				break;
			case 2:
				diff_pnom(&second_pnom, &res_pnom);
				printer(&res_pnom);
				free_polynomial(&res_pnom);
				break;
			}
			break;
		case 5:
			printf("***************\n");
			printf("\nEnter your NUM: ");
			scanf_s("%lf", &usernum);
			printf("\nEnter choosen POLYNOM: ");
			scanf_s("%d", &pnom_choice);
			switch (pnom_choice) {
			case 1: calculate(&first_pnom, usernum); printf("***************\n"); break;
			case 2: calculate(&second_pnom, usernum); printf("***************\n"); break;
			default: printf("Error. Only 2 polynoms exist"); break;
			}
		default:
			printf("Error, choose correct number.\n");
			break;
		}
	
	} while (flag);
	free_polynomial(&first_pnom);
	free_polynomial(&second_pnom);
	return 0;
}
