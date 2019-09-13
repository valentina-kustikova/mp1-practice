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
			message = "attempt to delete element from empty container";
		break;
		case 2:
			message = "attempt to delete non-existing element";
		break;
		case 3:
			message = "element does not exist";
		break;
		case 4:
			message = "element not found";
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