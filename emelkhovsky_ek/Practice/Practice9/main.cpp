#include "iostream"
#include "Exception.h"
#include "to_do_list.h"
#include "task.h"
#include "date.h"
#include "time.h"
#include "conio.h"
using namespace std;

int main(){
	todolist list;
	date dat;
	try{
		cin >> dat;
		list.read();
		list.print(dat);
	}
	catch (Exception err){
		err.Print();
	}
}