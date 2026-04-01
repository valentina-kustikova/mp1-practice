#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "funcs.h"
#include "data.h"

void find_vacancy(DbCompanies* comp_s, DbVacancies* vcn_s, DbCompanies *new_comp_s, char* users_choice) {
	int i, j, cnt = 0, k = 0;
	char* low_str1, low_str2;

	for (i = 0; i < vcn_s->size; i++) {
		if (_strnicmp(vcn_s->arr[i].name, users_choice, strlen(users_choice)) == 0) {
			cnt++;
		}
	}


	(*new_comp_s).size = cnt;
	(*new_comp_s).arr = (Company*)malloc(sizeof(Company) * cnt);

	for (i = 0; i < vcn_s->size; i++) {
		if (_strnicmp(vcn_s->arr[i].name, users_choice, strlen(users_choice)) == 0) {
			int id = vcn_s->arr[i].company_id-1;
			(*new_comp_s).arr[k].company_id = comp_s->arr[id].company_id;
			(*new_comp_s).arr[k].name = _strdup(comp_s->arr[id].name);
			(*new_comp_s).arr[k++].addres = _strdup(comp_s->arr[id].addres);

		}
	}
	
}

void different_company(DbCompanies* old_valid, DbCompanies* new_valid) {
	int i, j, cnt = 0, k=0;
	for (i = 0; i < old_valid->size; i++) {
		int flag = 1;
		for (j = 0; j < i; j++) {
			if (old_valid->arr[i].company_id == old_valid->arr[j].company_id) { 
				flag = 0;
				break;
			}
		}

		if (flag) {
			cnt++;
		}
	}

	new_valid->size = cnt;
	new_valid->arr = (Company*)malloc(sizeof(Company) * cnt);

	for (i = 0; i < old_valid->size; i++) {
		int flag = 1;
		for (j = 0; j < i; j++) {
			if (old_valid->arr[i].company_id == old_valid->arr[j].company_id) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			new_valid->arr[k].company_id = old_valid->arr[i].company_id;
			new_valid->arr[k].name = _strdup(old_valid->arr[i].name);
			new_valid->arr[k++].addres = _strdup(old_valid->arr[i].addres);
		}
	}
}