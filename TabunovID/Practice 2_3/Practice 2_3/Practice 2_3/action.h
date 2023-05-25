#pragma once
//#ifndef _actionh_
//#define _actionh_

#include <string>
#include <ostream>
#include <istream>

using namespace std;

void output();

struct team {
	string Name;
	string City;
	int Games;
	int Points;
	int Players;
	team(string Name, string City, int Games, int Points, int Players) {
		this->Name = Name;
		this->City = City;
		this->Games = Games;
		this->Points = Points;
		this->Players = Players;
	}
	team() : team("", "", 0, 0, 0) {

	}
};

ostream& operator<< (ostream& stream, const team& team) {
	stream << team.Name << endl << team.City << endl << team.Games << endl << team.Points << endl << team.Players << endl;
	return stream;
}

istream& operator>> (istream& stream, team& team) {
	stream >> team.Name >> team.City >> team.Games >> team.Points >> team.Players;
	return stream;
}

struct teamarray {
	team* teams;
	size_t length;
	~teamarray() {
		if (teams != nullptr) {
			delete[] teams;
		}
	}
};






//#endif