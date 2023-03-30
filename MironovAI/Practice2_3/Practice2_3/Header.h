#pragma once

#pragma once
#ifndef _Header_bankh_
#define _Header_bankh_
#define MAX_PATH 100 // Max path length 
#define MAX_NAME 20  // Max name of banks length
using namespace std;


struct triple {
	int id1;
	int id2;
	float profit;
	//default constuctor and destructor
};

class Deposit {
private:
	string name;
	int period;
	float conditions;
public:
	//default contructor axnd destructor
	int get_period() const;
	float get_condition() const;
	string get_name() const;
	friend ifstream& operator>>(ifstream& buf, Deposit& data);
	friend ostream& operator<<(ostream& buf, const Deposit& data);
};

class BanksData {
private:
	string name;
	string ownership;
	int count;
	int user_year;//можно в public
	float user_money;//also
	vector<Deposit> deposits;
	pair<int, float> best_suggestion;

public:
	//Constructor
	BanksData() {
		name = "";
		ownership = "";
		count = -1;
		user_money = -1;
		user_year = -1;
		best_suggestion.first = -1;
		best_suggestion.second = -1;
		deposits.resize(1);
	}
	//Destructor
	~BanksData()
	{
		deposits.resize(0);
	}

	//overloading operations
	pair<int, float> best_deposit(int user_year, float user_money);
	bool operator>(BanksData sd) {
		if (best_suggestion.second > sd.best_suggestion.second) return true;
		return false;
	}
	bool operator<(BanksData sd) {
		if (best_suggestion.second < sd.best_suggestion.second) return true;
		return false;
	}
	friend ifstream& operator>>(ifstream& buf, BanksData& data);
	friend ostream& operator<<(ostream& buf, const BanksData& data);

	//input data
	static int read(BanksData*& data, int* n, const string& path);

	//Getters
	pair<int, float> get_best_suggestion() const;
	string get_name() const;
	string get_ownership() const;
	vector<Deposit> get_deposits() const;

	//Setter
	void set_best_suggestion(pair<int, float> new_suggesition);
};



void input_path(string& path);
//void print_data(BanksData* data, int n);
void input_user_data(int* user_year, float* user_money);

triple comparing(BanksData* data, int user_year, float user_money, int n);
#endif

