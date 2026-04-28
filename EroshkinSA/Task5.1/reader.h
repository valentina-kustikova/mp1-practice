#ifndef __SEREADER_H
#define __SEREADER_H

int fcount(char dir[], int* pmx);
void read(char dir[], char flag, char** name, int* sz, int* num);

#endif