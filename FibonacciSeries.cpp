//FIBONACCI SERIES
#include<iostream>
using namespace std;

void printFibonacciSeries(int range);
int* getFibonacciSeriesList(int* list, int range);

//Driver Function
int main()
{
	printFibonacciSeries(10);
}

//INPUT: limit for sereis to be printed
void printFibonacciSeries(int range)
{
	int* list = new int[range];
	list=getFibonacciSeriesList(list, range);
	for (int i = 0; i < range; i++)
		cout << list[i] << " ";
	delete[] list;
}
//INPUT: limit: range of series, int list: to store series
//RETURNS: int list of series to range
int* getFibonacciSeriesList(int* list, int range)
{
	int x = 0, y = 1, sum = 0;
	for (int i = 0; i < range; i++)
	{
		list[i] = sum;
		sum = x + y;
		y = x;
		x = sum;
	}
	return list;
}
