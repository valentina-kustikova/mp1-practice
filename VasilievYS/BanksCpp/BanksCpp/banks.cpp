#include"banks.h"
#include"auxiliary.h"
#include<fstream>
#include<iostream>
banks_library::banks_library(const std::string& fr)
{
	std::ifstream file(fr);
	if (!file.is_open()) { throw std::string("File not found"); }
	this->cnt = 0;
	std::string str;
	while (getline(file, str))
	{
		this->cnt++;
	}
	this->banks = new bank[this->cnt];
	file.clear(); file.seekg(0);
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
		banks[i].name = line.substr(0, del_pos);
		size_t temp_del = del_pos;
		del_pos = line.find(del);
		banks[i].owner = line.substr(temp_del+2, del_pos - 2 - temp_del);
		line[del_pos] = ' ';
		for (int j = 0; j < banks[i].depostes_cnt; j++)
		{
			size_t comma_pos = line.find(','); line[comma_pos] = ' ';
			std::string n_name = line.substr(del_pos+2, comma_pos - 2 - del_pos);
			to_low(n_name);
			banks[i].deposites[j].name = n_name;
			del_pos = line.find(del); line[del_pos] = ' ';
			banks[i].deposites[j].percentage = stof(line.substr(comma_pos, del_pos - comma_pos));
		}
	}
	file.close();
}

banks_library::~banks_library()
{
	for (int i = 0; i < cnt; i++)
	{
		delete[]banks[i].deposites;
	}
	delete[]banks;
}

const bank& banks_library::find(const std::string& udep) const
{
	int check = 0;
	int* idx_list = new int[cnt];
	float* percent_list = new float[cnt];
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < banks[i].depostes_cnt; j++)
		{
			if (banks[i].deposites[j].name.find(udep) != std::string::npos)
			{
				idx_list[check] = i;
				percent_list[check] = banks[i].deposites[j].percentage;
				check++;
				break;
			}
		}
	}
	if (check == 0) {
		delete[]idx_list;
		delete[]percent_list;
		throw std::string("No matches");
	}
	float max_p = percent_list[0];
	int idx = 0;
	for (int i = 1; i < check; i++)
	{
		if (percent_list[i] > max_p) { max_p = percent_list[i]; idx = i; }
	}
	int ans_idx = idx_list[idx];
	delete[]idx_list;
	delete[]percent_list;
	return banks[ans_idx];
}

std::ostream& operator<<(std::ostream& os, const banks_library& lib)
{
	for (int i = 0; i < lib.cnt; i++)
	{
		os << lib.banks[i].name << "; " << lib.banks[i].owner << '\n';
		for (int j = 0; j < lib.banks[i].depostes_cnt; j++)
		{
			os << lib.banks[i].deposites[j].name << "; " << lib.banks[i].deposites[j].percentage << '\n';
		}
		os << '\n';
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const bank& b)
{
	return os << b.name << std::endl;
}