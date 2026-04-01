#ifndef _FUNCS_H
#define _FUNCS_H

#include "data.h"

#define max_simbols_in_line 512

void u_answer(char** user, int max);
int scan_company(char* link);
int scan_vacancy(char* link);
void fill_company(DbCompanies *Db, char* link);
void fill_vacancy(DbVacancies* Db, char* link);
void enter_the_vcn(char* users_choice);
int print_company(DbCompanies* dif_valid_comp_s);
void print_info(Company* valid_comp_s, DbVacancies* vcn_s);
void free_company(DbCompanies* Db);
void free_vacancy(DbVacancies* Db);



#endif