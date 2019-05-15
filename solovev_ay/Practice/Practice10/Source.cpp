#include "container.h"
using namespace std;

int main()
{
	Container<int, 4> c1;
	Container<int, 4> c2;
	cout << "sozdal 2 containers c1, c2 pustie" << endl;
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
		cout << endl;
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
		cout << "ego index" << kek << endl;
		cout << "ishu element nesuzh" << endl;
		int keker = c2.Find(100);
		cout << "vivedu c2" << endl;
		c2.print();
		cout << "c2[0]=4" << endl;
		c2[0] = 4;
		cout << "vivedu c2" << endl;
		c2.print();
		cout << "dobavil 11" << endl;
		c2.Add(11);
		cout << "na get c2[1]" << endl;
		int rrr = c2[1];
		cout << rrr << endl;
		cout << "vivedu c2" << endl;
		c2.print();
		try
		{
			cout << "add 14" << endl;
			c2.Add(14);
			cout << "vivedu c2" << endl;
			c2.print();
		}
		catch (const char* k)
		{
			std::cout << k;
		}
		cout << endl;
		try
		{
			cout << "nesush index c2[-1]=0" << endl;
			c2[-1] = 0;
		}
		catch (const char* k)
		{
			std::cout << k;
		}
		cout << endl;
		cout << "udalu 9 from c2" << endl;
		c2.Delete(9);
		cout << "vivedu c2" << endl;
		c2.print();
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	std::cout << std::endl << "konec probi 1" << std::endl << std::endl;
	cout << "part 2" << endl;
	Container<int*, 3> rofl;
	Container<int*, 10> kek;
	cout << "sozdam 2 pustyh containers rofl+kek" << endl;
	int*a1 = new int;
	*a1 = 7;
	int*a2 = new int;
	*a2 = 15;
	int*a3 = new int;
	*a3 = 105;
	cout << "*a1 = 7, *a2 = 15, *a3 = 105" << endl;
	cout << "k roflu dobavlu a2" << endl;
	rofl.Add(a2);
	cout << "k roflu dobavlu a1" << endl;
	rofl.Add(a1);
	cout << "k roflu dobavlu a3" << endl;
	rofl.Add(a3);
	cout << "v rofle naidu a3" << endl;
	cout << "index" << rofl.Find(a3) << endl;
	cout << "vivedu rofl" << endl;
	rofl.print();
	cout << "from rofl udaly a1" << endl;
	rofl.Delete(a1);
	cout << "vivedu rofl" << endl;
	rofl.print();
	cout << "pereidem k keku" << endl;
	try
	{
		cout << "udalu from pustoy kek el a1" << endl;
		kek.Delete(a1);
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	cout << endl;
	cout << "k keku dobavlu a2" << endl;
	kek.Add(a2);
	cout << "vuvedu kek" << endl;
	kek.print();
	cout << "kek[0]=a1(7)" << endl;
	*kek[0] = *a1;
	cout << "vuvedu kek" << endl;
	kek.print();
	cout << "vernu obratno" << endl;
	*kek[0] = *a2;
	try
	{
		cout << "naidu otdelniy element kek[0]" << endl;
		int* super = kek[0];
		cout << "a vot on ya" << *super << endl;
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	try
	{
		cout << "ishu index elementa a2=15" << endl;
		int rupor = kek.Find(a2);
		cout << rupor << endl;
	}
	catch (const char* k)
	{
		std::cout << k;
	}
	system("pause");
}