#include"banks.h"
#include"auxiliary.h"
#include<cstdio>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<cctype>

int cnt_s(const char* fr)
{
	FILE* fp = fopen(fr, "r");
	if (fp == NULL) { printf("File not found"); return NULL; }
	int cnt = 0;
	char ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch == '\n') { cnt++; }
		ch = fgetc(fp);
	}
	fclose(fp);
	return cnt;
}
void banks_library::cnt_banks(const std::string fr)
{
	std::ifstream file(fr);
	if(!file.is_open()) { throw std::exception("File not found");}
	this->cnt=0;
	std::string str;
	while (getline(file, str))
	{
		 this->cnt++;
	}
	file.close();
}
void banks_library::read_lib(const std::string fr)
{
	//FILE* fp = fopen(fr, "r");
	std::ifstream file(fr);
	for (int i = 0; i < this->cnt; i++)
	{
		std::string line, temp_line;
		getline(file, line);
		temp_line = line;
		char del = ';';
		size_t pos = line.find(del);
		while (pos != std::string::npos)
		{
			line[pos] = ' '; //доделать, посчитать количество ';' и минус 2,
		}
		std::string temp_token = strtok(temp_line, ";");
		temp_token = strtok(NULL, ";");
		temp_token = strtok(NULL, ";");
		while (temp_token != NULL)
		{
			if (strchr(temp_token, ',') != NULL) { dep_cnt++; }
			temp_token = strtok(NULL, ";");
		}
	}

}
void read(const char* fr, banks_library* lib)
{
	int check = 0, i;
	char line[MAX_LEN], temp_line[MAX_LEN], * token, * temp_token;
	FILE* fp = fopen(fr, "r");
	//std::ifstream file
	for (i = 0; i < lib->cnt; i++)
	{
		int dep_cnt = 0, cur_dep = 0;
		fgets(line, sizeof(line), fp);
		//кол-во депозитов
		strcpy(temp_line, line);
		temp_token = strtok(temp_line, ";");
		temp_token = strtok(NULL, ";");
		temp_token = strtok(NULL, ";");
		while (temp_token != NULL)
		{
			if (strchr(temp_token, ',') != NULL) { dep_cnt++; }
			temp_token = strtok(NULL, ";");
		}
		lib->banks[i].deposits_count = dep_cnt;
		lib->banks[i].deposites = (deposit*)malloc(sizeof(deposit) * dep_cnt);
		token = strtok(line, ";");
		strcpy(lib->banks[i].name, token);
		token = strtok(NULL, ";");
		strcpy(lib->banks[i].owner, token);
		token = strtok(NULL, ";");
		while (token != NULL)
		{
			char* comma = strchr(token, ',');
			if (comma == NULL)
			{
				token = strtok(NULL, ";");
				continue;
			}
			*comma = '\0';
			to_low(token);
			strcpy(lib->banks[i].deposites[cur_dep].name, token);
			lib->banks[i].deposites[cur_dep].percentage = atof(comma + 2);
			cur_dep++;
			token = strtok(NULL, ";");
		}
	}
	fclose(fp);
}

void to_low(char* str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		str[i] = tolower(str[i]);
	}
}

void print(bank* ans)
{
	int i;
	printf("%s; Ownership form:%s\n",
		ans->name, ans->owner);
}

void free_b(banks_library* lib)
{
	int i;
	for (i = 0; i < lib->cnt; i++)
	{
		free(lib->banks[i].deposites);
	}
	free(lib->banks);
}