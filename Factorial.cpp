#include<iostream>
using namespace std;

//INPUT: int 
//RETURNS: true or false
//METHOD: Checks if input is valid
bool inputValidation(int number)
{
	if (number <= 0)
	{
		cout << "INPUT NOT VALID ";
		return false;
	}
	return true;
}

//INPUT: int
//RETURNS: Factorial type int
//METHOD: Validates the input and uses Recursion
int calculateFactorial(int number)
{
	if (number == 1)
		return number;
	else
		return number * calculateFactorial(number - 1);
}

//DRIVER FUNCTION
void getFactorial(int number)
{
	if (!inputValidation(number))
		return;
	cout<<calculateFactorial(number);
}

int main()
{
	const int number = 5;
	getFactorial(number);
}