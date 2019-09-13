#include "mistakes.h"

mistakes::mistakes ()
{
	code = 0;
	message = "";
}

mistakes::mistakes (int i)
{
	code = i;
	switch (code)
	{	
		case 1:
			message = "file does not exist";
		break;
		case 2:
			message = "unknown type of day, only 1 or 2 are suitable";
		break;
		default: message = "unknown error";
	}
}

string mistakes::emesg () const
{
	return message;
}

int mistakes::ecode () const
{
	return code;
}

void mistakes::edrop() const
{
	cout << "Error " << code << " occured." << endl;
	cout << "Info: " << message << "." << endl << endl;
}