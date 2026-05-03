#include"auxiliary.h"
#include<cctype>
void to_low(std::string& str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = tolower(str[i]);
	}
}