#include"banks.h"
#include"auxiliary.h"
#include<fstream>
#include<iostream>
banks_library::banks_library(const std::string& fr)
{
	std::ifstream file(fr);
	if (!file.is_open()) { throw std::string("File not found"); }
	this->cnt=0;
	std::string str;
	while (getline(file, str))
	{
		this->cnt++;
	}
	this->banks = new bank[cnt];
	file.clear(); file.seekg(0);
	for (int i = 0; i < this->cnt; i++)
	{
		std::string line, temp_line;
		getline(file, line);
		temp_line = line;
		char del = ';';
		size_t del_pos = temp_line.find(del);
		banks[i].set_dep_cnt(0);
		while (del_pos != std::string::npos)
		{
			temp_line[del_pos] = ' ';
			banks[i]++;
			del_pos = temp_line.find(del);
		}
		banks[i] -= 2;
		banks[i].alloc_deps();
		del_pos = line.find(del);
		line[del_pos] = ' ';
		banks[i].set_name(line.substr(0, del_pos));
		size_t temp_del = del_pos;
		del_pos = line.find(del);
		banks[i].set_owner(line.substr(temp_del + 2, del_pos - 2 - temp_del));
		line[del_pos] = ' ';
		for (int j = 0; j < banks[i].get_deps_cnt(); j++)
		{
			size_t comma_pos = line.find(','); line[comma_pos] = ' ';
			std::string n_name = line.substr(del_pos + 2, comma_pos - 2 - del_pos);
			to_low(n_name);
			banks[i].set_dep_name(n_name, j);
			del_pos = line.find(del); line[del_pos] = ' ';
			banks[i].set_dep_perc(stof(line.substr(comma_pos, del_pos - comma_pos)), j);
		}
	}
	file.close();
}

banks_library::~banks_library()
{
	delete[] banks;
	banks = nullptr;
}
bank::~bank()
{
	delete[] deposites;
	deposites = nullptr;
}

bank::bank(const bank& b)
{
	name = b.name;
	owner = b.owner;
	depostes_cnt = b.depostes_cnt;
	deposites = new deposit[depostes_cnt];
}

const bank& banks_library::find(const std::string& udep) const
{
	int check = 0;
	int* idx_list = new int[cnt];
	float* percent_list = new float[cnt];
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < banks[i].get_deps_cnt(); j++)
		{
			if (banks[i].get_dep_name(j).find(udep) != std::string::npos)
			{
				idx_list[check] = i;
				percent_list[check] = banks[i].get_dep_perc(j);
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

void banks_library::set_banks_cnt(const int& n)
{
	cnt = n;
}

std::ostream& operator<<(std::ostream& os, const banks_library& lib)
{
	for (int i = 0; i < lib.cnt; i++)
	{
		os << lib.banks[i].get_name() << "; " << lib.banks[i].get_owner() << '\n';
		for (int j = 0; j < lib.banks[i].get_deps_cnt(); j++)
		{
			os << lib.banks[i].get_dep_name(j) << "; " << lib.banks[i].get_dep_perc(j) << '\n';
		}
		os << '\n';
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const bank& b)
{
	return os << b.name << std::endl;
}

bank bank::operator++(int)
{
	bank old = *this;
	this->depostes_cnt++;
	return old;
}

bank& bank::operator-=(int n)
{
	
	this->depostes_cnt -= n;
	return *this;
}

void bank::set_dep_cnt(int n)
{
	depostes_cnt = n;
}

void bank::set_name(const std::string& n)
{
	name = n;
}

void bank::set_owner(const std::string& own)
{
	owner = own;
}

void bank::set_dep_name(const std::string& n, int idx)
{
	if (idx >= depostes_cnt) { throw std::string("Out of range"); }
	deposites[idx].set_name(n);
}

void bank::set_dep_perc(const float& perc, int idx)
{
	if (idx >= depostes_cnt) { throw std::string("Out of range"); }
	deposites[idx].set_perc(perc);
}

void bank::alloc_deps()
{
	deposites = new deposit[depostes_cnt];
}

const int& bank::get_deps_cnt() const
{
	return depostes_cnt;
}

const float& bank::get_dep_perc(int j) const
{
	return deposites[j].get_perc();
}

const std::string& bank::get_dep_name(int j) const
{
	return deposites[j].get_name();
}

const std::string& bank::get_name() const
{
	return name;
}

const std::string& bank::get_owner() const
{
	return owner;
}

void deposit::set_name(const std::string& n)
{
	name = n;
}
void deposit::set_perc(const float& p)
{
	percentage = p;
}

const std::string& deposit::get_name() const
{
	return name;
}

const float& deposit::get_perc() const
{
	return percentage;
}