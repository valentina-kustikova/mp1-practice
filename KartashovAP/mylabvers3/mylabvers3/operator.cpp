#include "roster.h"

istream& operator>>(istream& in, FullName& a) {
	getline(in, a.surname, ';');
	getline(in, a.name, ';');
	getline(in, a.patronymic, ';');
	return in;
}

ostream& operator<<(ostream& out, const FullName& a) {
	out << a.surname << " " << a.name << " " << a.patronymic;
	return out;
}

istream& operator>>(istream& in, Date& a) {
	string ds, ms, ys;
	getline(in, ds, ';');
	getline(in, ms, ';');
	getline(in, ys, ';');

	int day = stoi(ds);
	int month = stoi(ms);
	int year = stoi(ys);

	bool valid = true;

	if (year < 1900 || year > 2026) valid = false;
	if (month < 1 || month > 12) valid = false;

	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		days_in_month[1] = 29;
	}

	if (day < 1 || day > days_in_month[month - 1]) valid = false;

	if (valid) {
		a = Date(day, month, year);
	}
	else {
		cerr << "INVALID DATE: " << day << "." << month << "." << year
			<< " -> REPLACED WITH 01.01.2000\n";
		a = Date(1, 1, 2000);
	}

	return in;
}

ostream& operator<<(ostream& out, const Date& a) {
	out << (a.day < 10 ? "0" : "") << a.day << "."
		<< (a.month < 10 ? "0" : "") << a.month << "."
		<< a.year;
	return out;
}

istream& operator>>(istream& in, Address& a) {
	string pc, c, r, d, ct, s, h, ap;
	getline(in, pc, ';');
	getline(in, c, ';');
	getline(in, r, ';');
	getline(in, d, ';');
	getline(in, ct, ';');
	getline(in, s, ';');
	getline(in, h, ';');
	getline(in, ap);

	a = Address(pc, c, r, d, ct, s, h, ap);
	return in;
}

ostream& operator<<(ostream& out, const Address& a) {
	out << a.postal_code << ", " << a.country << ", " << a.region
		<< ", " << a.district << ", " << a.city << ", "
		<< a.street << ", " << a.house;
	return out;
}

istream& operator>>(istream& in, Person& p) {
	FullName fn;
	in >> fn;

	string gender_str;
	getline(in, gender_str, ';');

	Gender g;
	if (gender_str == "M" || gender_str == "Male")
		g = male;
	else if (gender_str == "F" || gender_str == "Female")
		g = female;
	else
		g = unknown;

	Date bd;
	in >> bd;

	p = Person(fn, g, bd);
	return in;
}

ostream& operator<<(ostream& out, const Person& p) {
	out << p.full_name << "\n  Gender: ";
	switch (p.gender) {
	case male: out << "Male"; break;
	case female: out << "Female"; break;
	default: out << "Unknown";
	}
	out << "\n  Birth date: " << p.birth_date;
	return out;
}

istream& operator>>(istream& in, Student& s) {
	string line;
	getline(in, line);
	if (line.empty()) return in;

	stringstream ss(line);

	string surname, name, patronymic, class_name, gender_str;
	string day_str, month_str, year_str;
	string pc, c, r, d, ct, st, h, ap;

	getline(ss, surname, ';');
	getline(ss, name, ';');
	getline(ss, patronymic, ';');
	getline(ss, class_name, ';');
	getline(ss, gender_str, ';');
	getline(ss, day_str, ';');
	getline(ss, month_str, ';');
	getline(ss, year_str, ';');
	getline(ss, pc, ';');
	getline(ss, c, ';');
	getline(ss, r, ';');
	getline(ss, d, ';');
	getline(ss, ct, ';');
	getline(ss, st, ';');
	getline(ss, h, ';');
	getline(ss, ap);

	FullName fn(surname, name, patronymic);

	Gender gender;
	if (gender_str == "M" || gender_str == "Male")
		gender = male;
	else if (gender_str == "F" || gender_str == "Female")
		gender = female;
	else
		gender = unknown;

	int day = stoi(day_str);
	int month = stoi(month_str);
	int year = stoi(year_str);

	bool valid = true;
	if (year < 1900 || year > 2026) valid = false;
	if (month < 1 || month > 12) valid = false;

	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		days_in_month[1] = 29;
	}
	if (day < 1 || day > days_in_month[month - 1]) valid = false;

	Date birth_date;
	if (valid) {
		birth_date = Date(day, month, year);
	}
	else {
		cerr << "INVALID DATE: " << day << "." << month << "." << year
			<< " -> REPLACED WITH 01.01.2000\n";
		birth_date = Date(1, 1, 2000);
	}

	Address addr(pc, c, r, d, ct, st, h, ap);

	s = Student(fn, gender, birth_date, class_name, addr);
	return in;
}

ostream& operator<<(ostream& out, const Student& s) {
	out << "  " << (Person)s << "\n";
	out << "  Class: " << s.class_name << "\n";
	out << "  Address: " << s.address;
	return out;
}

istream& operator>>(istream& in, ClassGroup& a) {
	return in;
}

ostream& operator<<(ostream& out, const ClassGroup& a) {
	out << "\n========== Class " << a.getClassName()
		<< " (" << a.getCount() << " students) ==========\n";
	for (int i = 0; i < a.getCount(); i++)
		out << a.getStudents()[i] << "\n\n";
	return out;
}

istream& operator>>(istream& in, School& school) {
	Student all_students[100];
	int student_count = 0;
	string line;

	while (getline(in, line)) {
		if (line.empty()) continue;
		stringstream ss(line);
		Student s;

		string surname, name, patronymic, class_name, gender_str;
		string day_str, month_str, year_str;
		string pc, c, r, d, ct, st, h, ap;

		getline(ss, surname, ';');
		getline(ss, name, ';');
		getline(ss, patronymic, ';');
		getline(ss, class_name, ';');
		getline(ss, gender_str, ';');
		getline(ss, day_str, ';');
		getline(ss, month_str, ';');
		getline(ss, year_str, ';');
		getline(ss, pc, ';');
		getline(ss, c, ';');
		getline(ss, r, ';');
		getline(ss, d, ';');
		getline(ss, ct, ';');
		getline(ss, st, ';');
		getline(ss, h, ';');
		getline(ss, ap);

		FullName fn(surname, name, patronymic);

		Gender gender;
		if (gender_str == "M")
			gender = male;
		else if (gender_str == "F")
			gender = female;
		else
			gender = unknown;

		int day = stoi(day_str);
		int month = stoi(month_str);
		int year = stoi(year_str);

		bool valid = true;
		if (year < 1900 || year > 2026) valid = false;
		if (month < 1 || month > 12) valid = false;

		int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			days_in_month[1] = 29;
		}
		if (day < 1 || day > days_in_month[month - 1]) valid = false;

		Date birth_date;
		if (valid) {
			birth_date = Date(day, month, year);
		}
		else {
			cerr << "INVALID DATE: " << day << "." << month << "." << year
				<< " -> REPLACED WITH 01.01.2000\n";
			birth_date = Date(1, 1, 2000);
		}

		Address addr(pc, c, r, d, ct, st, h, ap);

		s = Student(fn, gender, birth_date, class_name, addr);
		all_students[student_count++] = s;
	}

	string unique_classes[50];
	int unique_count = 0;

	for (int i = 0; i < student_count; i++) {
		bool found = false;
		for (int j = 0; j < unique_count; j++) {
			if (all_students[i].getClassName() == unique_classes[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			unique_classes[unique_count] = all_students[i].getClassName();
			unique_count++;
		}
	}

	school.class_count = unique_count;
	school.classes = new ClassGroup[unique_count];

	for (int i = 0; i < unique_count; i++) {
		school.classes[i] = ClassGroup(unique_classes[i]);
	}

	for (int i = 0; i < student_count; i++) {
		for (int j = 0; j < unique_count; j++) {
			if (all_students[i].getClassName() == school.classes[j].getClassName()) {
				school.classes[j].addStudent(all_students[i]);
				break;
			}
		}
	}

	return in;
}

ostream& operator<<(ostream& out, const School& a) {
	for (int i = 0; i < a.class_count; i++)
		out << a.classes[i];
	return out;
}