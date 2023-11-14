#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++) 
		cout << setw(4) << a[i] << ", ";
		cout << endl;
}

int Sum(int* a, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (!(a[i] % 2 == 0 || a[i] >= 0))
			S += a[i];
	return S;
}

int Number(int* a, const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (!(a[i] % 2 == 0 || a[i] >= 0))
			count++;
	return count;
}

void Replace(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] % 2 == 0 || a[i] >= 0)
			a[i] = 0;
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 24;
	int a[n];
	int Low = -50;
	int High = 15;

	Create(a, n, Low, High);
	cout << "Unmodified array " << endl;
	Print(a, n);

	int sum = Sum(a, n);
	int count = Number(a, n);
	Replace(a, n);
	
	//cout << "S = " << Sum(a, n, 0, 0) << endl;
	cout << "Modified array " << endl;
	Print(a, n);

	cout << "Number of elements is " << count << endl;
	cout << "Sum of elements is " << sum << endl;

	return 0;
}