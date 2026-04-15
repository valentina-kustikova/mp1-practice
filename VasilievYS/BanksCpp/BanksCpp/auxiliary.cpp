#include"banks.h"
#include"auxiliary.h"
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<cctype>
#include<iostream>
banks_library::banks_library()
{
	this->cnt = 0;
	this->banks = nullptr;
}

void banks_library::make_list()
{
	this->banks = new bank[this->cnt];
}

banks_library::~banks_library()
{
	for (int i = 0; i < cnt; i++)
	{
		delete[]banks->deposites;
	}
	delete[]banks;
}

void banks_library::cnt_banks(const std::string& fr)
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

void banks_library::read_lib(const std::string& fr)
{
	std::ifstream file(fr);
	for (int i = 0; i < this->cnt; i++)
	{
		std::string line, temp_line;
		getline(file, line);
		temp_line = line;
		char del = ';';
		size_t del_pos = temp_line.find(del);
		banks[i].depostes_cnt = 0;
		while (del_pos != std::string::npos)
		{
			temp_line[del_pos] = ' ';
			banks[i].depostes_cnt++;
			del_pos = temp_line.find(del);
		}
		banks[i].depostes_cnt -= 2;
		banks[i].deposites = new deposit[banks[i].depostes_cnt];
		del_pos = line.find(del);
		line[del_pos] = ' ';
		del_pos = line.find(del);
		line[del_pos] = ' ';
		for (int j = 0; j < banks[i].depostes_cnt; j++)
		{
			size_t comma_pos = line.find(','); line[comma_pos] = ' ';
			std::string n_name = line.substr(del_pos, comma_pos - del_pos + 1);
			to_low(n_name);
			banks[i].deposites[j].name = n_name;
			del_pos = line.find(del); line[del_pos] = ' ';
			banks[i].deposites[j].percentage = stof(line.substr(comma_pos, del_pos - comma_pos + 1));
		}
		std::cout << 1234;
	}
	file.close();
}

void to_low(std::string& str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = tolower(str[i]);
	}
}

std::ostream& operator<<(std::ostream& os, const bank& b)
{
	return os << b.name << std::endl;
}