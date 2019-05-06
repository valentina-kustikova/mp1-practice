#include "container.h"

#define PRINT(a, b) std::cout << std::endl; \
        for(int i = 0; i < a; i++) std::cout << b[i] << std::endl; 
int main()
{
	Container<int, 4> c1;
	Container<int, 4> c2;
	Container<int, 4> c3(c2);
	try
	{
		try
		{
			c1.Delete(9);
		}
		catch (const char* k)
		{
			std::cout << k;
		}
		std::cout << c3.IsFull() << std::endl;
		std::cout << c3.IsEmpty() << std::endl;
		c3.Add(3);
		c3.Add(9);
		c3.Add(7);
		std::cout << c3.IsEmpty() << std::endl;
		std::cout << c3.Find(9) << std::endl;
		PRINT(c3.getcount(), c3);
		c3[0] = 4;
		PRINT(c3.getcount(), c3);
		c3.Add(11);
		PRINT(c3.getcount(), c3);
		try
		{
			c3.Add(14);
			PRINT(c3.getcount(), c3);
		}
		catch (const char* k)
		{
			std::cout << k;
		}
		try
		{
			c3[-1] = 0;
		}
		catch (const char* k)
		{
			std::cout << k;
		}
		c3.Delete(9);
		PRINT(c3.getcount(), c3);
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	catch (...)
	{
		std::cout << std::endl << "I don't know what was happened. I'm scared. \
      I cann't fix it. I'm just a computer. :(" << std::endl;
	}





	std::cout << std::endl << "End of Container!" << std::endl << std::endl;



	system("pause");

}
/*	{
		Container<int*, 4> c1;
		Container<int*, 4> c2;
		Container<int*, 4> c3(c2);
		int* a1 = new int, *a2 = new int, *a3 = new int, *a4 = new int, *a5 = new int, *a6 = new int;
		*a1 = 3;
		*a2 = 9;
		*a3 = 7;
		*a4 = 11;
		*a5 = 14;
		*a6 = 4;
		try
		{
			try
			{
				c1.Delete(a2);
			}
			catch (MyException const& e)
			{
				std::cout << "Error: " << e.what() << std::endl;
				std::cout << "Reason: " << e.why() << std::endl;
				std::cout << "errorLine: " << e.errorLine();
				std::cout << "\nerrorFile:" << e.errorFile() << std::endl;
			}
			std::cout << c3.IsFull() << std::endl;
			std::cout << c3.IsEmpty() << std::endl;
			c3.Add(a1);
			c3.Add(a2);
			c3.Add(a3);
			std::cout << c3.IsEmpty() << std::endl;
			std::cout << c3.Find(9) << std::endl;
			PRINT_P(c3.getCount(), c3);
			*c3[0] = *a6;
			PRINT_P(c3.getCount(), c3);
			c3.Add(a4);
			PRINT_P(c3.getCount(), c3);
			try
			{
				c3.Add(a5);
				PRINT_P(c3.getCount(), c3);
			}
			catch (MyException const& e)
			{
				std::cout << "Error: " << e.what() << std::endl;
				std::cout << "Reason: " << e.why() << std::endl;
				std::cout << "errorLine: " << e.errorLine();
				std::cout << "\nerrorFile:" << e.errorFile() << std::endl;
			}
			try
			{
				*c3[-1] = *a6;
			}
			catch (MyException const& e)
			{
				std::cout << "Error: " << e.what() << std::endl;
				std::cout << "Reason: " << e.why() << std::endl;
				std::cout << "errorLine: " << e.errorLine();
				std::cout << "\nerrorFile:" << e.errorFile() << std::endl;
			}
			c3.Delete(a2);
			PRINT_P(c3.getCount(), c3);
		}
		catch (MyException const& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			std::cout << "Reason: " << e.why() << std::endl;
			std::cout << "errorLine: " << e.errorLine();
			std::cout << "\nerrorFile:" << e.errorFile() << std::endl;
		}
		catch (...)
		{
			std::cout << std::endl << "I don't know what was happened. I'm scared. \
      I cann't fix it. I'm just a computer. :(" << std::endl;
		}
	}

	return 0;
}
*/