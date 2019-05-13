#include "container.h"
using namespace std;

int main()
{
	Container<int, 4> c1;
	Container<int, 4> c2;
	cout << " 2 containers c1, c2 empty" << endl;
	try
	{
		try
		{
			cout << "try delete 9 from c1" << endl;
			c1.Delete(9);
		}
		catch (const char* k)
		{
			std::cout << k;
		}
		cout << "proverka c2 na plnotu" << endl;
		std::cout << c2.IsFull() << std::endl;
		cout << "proverka c2 na pustotu" << endl;
		std::cout << c2.IsEmpty() << std::endl;
		cout << "dobavil k c2 3" << endl;
		c2.Add(3);
		cout << "dobavil k c2 9" << endl;
		c2.Add(9);
		cout << "dobavil k c2 7" << endl;
		c2.Add(7);
		cout << "ishu index elementa=9" << endl;
		int kek = c2.Find(9);
		cout << kek << endl;
		cout << "ishu element nesuzh" << endl;
		int keker = c2.Find(100);
		c2.print();
		cout << "c2[0]=4" << endl;
		c2[0] = 4;
		c2.print();
		cout << "dobavil 11" << endl;
		c2.Add(11);
		c2.print();
		try
		{
			c2.Add(14);
			c2.print();
		}
		catch (const char* k)
		{
			std::cout << k;
		}
		try
		{
			c2[-1] = 0;
		}
		catch (const char* k)
		{
			std::cout << k;
		}
		c2.Delete(9);
		c2.print();
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	std::cout << std::endl << "konec probi" << std::endl << std::endl;
	cout << "part 2" << endl;
	Container<int*, 6> rofl;
	Container<int*, 10> kek;
	int*a1 = new int;
	*a1 = 7;
	int*a2 = new int;
	*a2 = 15;
	int*a3 = new int;
	*a3 = 105;
	rofl.Add(a2);
	rofl.Add(a1);
	rofl.Add(a3);
	cout << "nomer" << rofl.Find(a3) << endl;
	rofl.print();
	rofl.Delete(a1);
	rofl.print();
	try
	{
		kek.Delete(a1);
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	kek.Add(a2);
	kek.print();
	try
	{
		int* super = kek[0];
		cout << super << endl;
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	system("pause");
}