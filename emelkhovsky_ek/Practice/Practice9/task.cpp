#include "date.h"
#include "task.h"
#include "string"
#include "locale.h"
using namespace std;
task::task() {
}
task::task(string describe1, date dat) {
	describe = describe1;
	date_m = dat;
}
task::~task() {
	describe.clear();
}
date task::receipt() {
	return date_m;
};