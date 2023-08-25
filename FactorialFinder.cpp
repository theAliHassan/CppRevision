#include<iostream>
using namespace std;

int getFactorial(int number)
{
	if (number == 1 )
		return number;
	else
		return number * getFactorial(number - 1);
}
bool getInputValidation(int start, int end)
{
	if (start < 1 || end < start)
		return false;
	return true;
}
void printFactorials(int start, int end)
{
	if (!getInputValidation(start,end))
		return;

	for (int i = start; i <= end; i++)
		cout << getFactorial(i) << " ";
	return;
}

int main()
{
	printFactorials(1, 10);
}