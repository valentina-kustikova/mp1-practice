#include "timetable.h"

#define MAX_LEN 100

timetable::timetable()
{
    todo = nullptr;
    count = 0;
}

timetable::timetable(unsigned n)
{
    count = n;
    todo = new task*[n];
}

timetable::~timetable()
{
    for (int i = 0; i < (int) count-1; i++)
        delete[] todo[i];
    delete[] todo;
    count = 0;
}

void timetable::counttasks (const date& d) const
{
	int ntasks = 0;
	for (int i = 0; i < (int) count; i++)
    {
        if (todo[i]->GetNote() == d)
			ntasks ++;
	}
	cout << "total: " << ntasks << " tasks for this day" << endl << endl;
}

void timetable::print(date d) const // สฬ
{
    d.print();
	int ntasks = 0;
    for (int i = 0; i < (int) count; i++)
    {
        if (todo[i]->GetNote() == d)
        {
            todo[i]->print();
        }
		
    }

}


void timetable::read(string s) // ะส
{
    ifstream fin(s);
    if (fin.is_open() == false)
        throw (mistakes (1));
    fin >> count;

    todo = new task*[count];

    int type;

    for (int i = 0; i < (int) count; i++)
    {
        fin >> type;

		if ((type == 1) || (type == 2))
			getcalendar (type, fin, i);
		else
			throw (mistakes (2));
    }
}

void timetable::getcalendar (int type, istream& f, int i)
{
	int year, month, day;
    char* c = new char[MAX_LEN];
    unsigned min, hour, dur;
	string s1, s2;

	size_t pos1, pos2;
    f.getline(c, MAX_LEN); // _dd.mm.yyyy_<info>
    s1 = string(c); 

    pos1 = s1.find("."); // [_] -> dd {.} mm.yyyy_<info> 
    pos2 = s1.rfind(" ", pos1); // {_} dd <- [.] mm.yyyy_<info> 
    s2 = s1.substr((pos2 + 1), (pos1 - pos2 - 1)); // s2 = {dd}
    day = atoi(s2.c_str()); // dd -> array of char -> int
    s2 = "";

    pos2 = s1.find(".", pos1 + 1); // _dd "." mm {.} yyyy_<info>
    s2 = s1.substr((pos1 + 1), (pos2 - pos1 - 1));  // s2 = {mm}
    month = atoi(s2.c_str()); 
    s2 = "";

    pos1 = s1.find(" ", pos2); // _dd.mm "." yyyy {_} <info>
    s2 = s1.substr((pos2 + 1), (pos1 - pos2 - 1)); // s2 = {yyyy}
    year = atoi(s2.c_str()); 
    s2 = "";

	date note = date(year, month, day);

	if (type == 2)
    {
        pos2 = s1.find(":"); // _dd.mm.yyyy "_" hh {:} mm <dur> <info>
		s2 = s1.substr((pos1 + 1), (pos2 - pos1 - 1)); // s2 = {hh}
        hour = atoi(s2.c_str());
        s2 = "";

        pos1 = s1.find(" ", pos2); // _dd.mm.yyyy_hh ":" mm { } <dur> <info>
        s2 = s1.substr((pos2 + 1), (pos1 - pos2 - 1)); // s2 = {mm}
        min = atoi(s2.c_str());
        s2 = "";

        pos2 = s1.find_first_of("1234567890", pos1);  // _dd.mm.yyyy_hh:mm " " {<}dur> <info>
        pos1 = s1.find(" ", pos2); // _dd.mm.yyyy_hh:mm " " <dur>{ }<info>
        s2 = s1.substr(pos2, (pos1 - pos2)); // _dd.mm.yyyy_hh:mm {<dur>} <info>
        dur = atoi(s2.c_str());
        s2 = "";

		time clock = time (hour, min);
		todo [i] = new task2("", note, clock, dur);
	}
	else if (type == 1)
		todo [i] = new task1("", note);

	        pos2 = s1.find("/0", pos1); // _dd.mm.yyyy "_" <info> {/0}
            s2 = s1.substr((pos1 + 1), (pos2 - pos1 - 1)); // s2 = {<info>}
            s1 = s2; 
            s2 = "";

			todo [i]->changeinfo(s1);
}

//"find" starts from 0; straight ->; gives น from beginning;
//"rfind" starts from 'pos1'; reverse <-; gives น from beginning