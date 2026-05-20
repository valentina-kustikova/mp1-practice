#include <iostream>
#include <clocale> 
#include <cmath>
#include <fstream> 
#include <string>

using namespace std;
#include "funcs.h"

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

Point::Point() {
  x = 0;
  y = 0;
}