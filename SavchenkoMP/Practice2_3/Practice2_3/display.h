#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "polynom.h"

void choose();
void answer(int& ans);
void retry(int& ans);

void print_p(TPolynom*& p, const int n);
void index(int* ind, const int n);
void print_2p(TPolynom& p1, TPolynom& p2, int* ind);


#endif // !_DISPLAY_H