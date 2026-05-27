#ifndef __AUXDEP_H_
#define __AUXDEP_H_
#include "department.h"


int countRowsInFile(const std::string& filename);
void fillOwnersArray(std::ifstream& f, Owner* owners, int count);

#endif