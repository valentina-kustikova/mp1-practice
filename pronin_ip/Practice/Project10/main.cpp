#include "container.h"
#include "container+.h"
void main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	float b[] = { 1.1f, 2.22f, 3.03f, 4.f, -5.5f };
	cout << "Container 1:" << endl;
	Container <int, 6> container_1(5, a);
	cout << container_1 << endl;
	try
	{
		container_1.Add(2); //exeption
	}
	catch (const char* problem)
	{
		cout << problem << endl;
	}
	container_1.Add(6);
	container_1.Add(7);
	container_1.Delete(1);
	try
	{
		container_1.Deletebyidx(-1); //exeption
	}
	catch (const char* problem)
	{
		cout << problem << endl;
	}
	cout << container_1 << endl;

	cout << endl;

	cout << "Container 2:" << endl;
	Container <float, 7> container_2(5, b);
	cout << container_2 << endl;
	try
	{
		container_2.Add(2.22f); // exeption
	}
	catch (const char* problem)
	{
		cout << problem << endl;
	}
	container_2.Add(6.666f);
	container_2.Add(-7.07f);
	container_2.Delete(1.1f);
	cout << container_2 << endl;

	int* a1[5];
	float* b1[5];
	for (int i = 0; i < 5; i++)
	{
		a1[i] = &a[i];
		b1[i] = &b[i];
	}
	cout << endl;

	cout << "Container 3:" << endl;
	Container <int*, 6> container_3(5, a1);
	cout << container_3 << endl;
	int elem = 2;
	int elem1 = 6;
	int elem2 = 7;
	int elem3 = 1;
	int *p = &elem;
	int *p1 = &elem1;
	int *p2 = &elem2;
	int *p3 = &elem3;
	try
	{
		container_3.Add(p);
	}
	catch (const char* problem)
	{
		cout << problem << endl; //exeption
	}
	container_3.Add(p1);
	container_3.Add(p2);
	container_3.Delete(p3);
	cout << container_3 << endl;

	cout << endl;

	cout << "Container 4:" << endl;
	Container <float*, 7> container_4(5, b1);
	cout << container_4 << endl;
	float elem_ = 2.22;
	float elem1_ = 6.666;
	float elem2_ = -7.07;
	float elem3_ = 1.1;
	float *p_ = &elem_;
	float *p1_ = &elem1_;
	float *p2_ = &elem2_;
	float *p3_ = &elem3_;
	try
	{
		container_4.Add(p_);
	}
	catch (const char* problem)
	{
		cout << problem << endl; //exeption
	}
	container_4.Add(p1_);
	container_4.Add(p2_);
	container_4.Delete(p3_);
	cout << container_4 << endl;

	system("pause");
}