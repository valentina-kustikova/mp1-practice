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
	this->banks = new bank[this->cnt];
	file.clear(); file.seekg(0);
	for (int i = 0; i < this->cnt; i++)
	{
		std::string line, temp_line;
		int deps_cnt = 0;
		getline(file, line);
		temp_line = line;
		char del = ';';
		size_t del_pos = temp_line.find(del);
		while (del_pos != std::string::npos)
		{
			temp_line[del_pos] = ' ';
			deps_cnt++;
			del_pos = temp_line.find(del);
		}
		deps_cnt -= 2;
		deposit* deps_list = new deposit[deps_cnt];
		del_pos = line.find(del);
		line[del_pos] = ' ';
		std::string name_bank = line.substr(0, del_pos);
		size_t temp_del = del_pos;
		del_pos = line.find(del);
		std::string owner_bank = line.substr(temp_del + 2, del_pos - 2 - temp_del);
		line[del_pos] = ' ';
		for (int j = 0; j < deps_cnt; j++)
		{
			size_t comma_pos = line.find(','); line[comma_pos] = ' ';
			std::string dep_name = line.substr(del_pos + 2, comma_pos - 2 - del_pos);
			to_low(dep_name);
			del_pos = line.find(del); line[del_pos] = ' ';
			float dep_per = stof(line.substr(comma_pos, del_pos - comma_pos));
			deps_list[j] = deposit(dep_name, dep_per);
		}
		banks[i] = bank(name_bank, owner_bank, deps_list, deps_cnt);
	}
	file.close();
}
bank::bank(const std::string _n, const std::string _o,
deposit* _d, const int d_cnt)
{
	name = _n;
	owner = _o;
	deposites = _d;
	depostes_cnt = d_cnt;
}

bank::bank(const bank& b)
{
	name = b.name;
	owner = b.owner;
	depostes_cnt = b.depostes_cnt;
	deposites = new deposit[depostes_cnt];
	for (int i = 0; i < depostes_cnt; i++)
	{
		deposites[i] = b.deposites[i];
	}
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

bank& bank::operator=(const bank& b)
{
	if (this != &b) {
		name = b.name;
		owner = b.owner;
		depostes_cnt = b.depostes_cnt;
		delete[]deposites;
		deposites = new deposit[depostes_cnt];
		for (int i = 0; i < depostes_cnt; i++)
		{
			deposites[i] = b.deposites[i];
		}
	}
	return *this;
}
deposit& deposit::operator=(const deposit& d)
{
	name = d.name;
	percentage = d.percentage;
	return *this;
}

const bank banks_library::find(const std::string& udep) const
{
	int check = 0, max_idx = 0;
	float max_p = -1;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < banks[i].get_deps_cnt(); j++)
		{
			if (banks[i].get_dep_name(j).find(udep) != std::string::npos)
			{
				float cur_p = banks[i].get_dep_perc(j);
				if (cur_p > max_p)
				{
					max_p = cur_p;
					max_idx = i;
				}
				check++;
				break;
			}
		}
	}
	if (check == 0) {
		throw std::string("No matches");
	}
	return banks[max_idx];
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

const int bank::get_deps_cnt() const
{
	return depostes_cnt;
}

const float bank::get_dep_perc(int j) const
{
	return deposites[j].get_perc();
}

const std::string bank::get_dep_name(int j) const
{
	return deposites[j].get_name();
}

const std::string bank::get_name() const
{
	return name;
}

const std::string bank::get_owner() const
{
	return owner;
}

const std::string deposit::get_name() const
{
	return name;
}

const float deposit::get_perc() const
{
	return percentage;
}