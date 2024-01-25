#include<iostream>
#include<string>
using namespace std;


class ArmstrongNumber
{
public:
	ArmstrongNumber();
	~ArmstrongNumber();
	
	void isArmstrongNumber(int input)
	{
		if (this->getArmstrongNumber(input))
			cout << "IS ARMSTRONG NUMBER" << endl;
		else
			cout << "NOT AN ARMSTRONG NUMBER" << endl;
	}

	void printArmstrongNumbers(int domain,int range)
	{
		for (int i = domain; i < range; i++)
			if (this->getArmstrongNumber(i))
				cout << i << "  ";
	}



private:
	int* number;

	//INPUT: string 
	//OUTPUT: int List
	//Example: "421" RETURNS {4,2,1} 
	int* toIntList(string number)
	{
		int* list = new int[number.length()];
		for (int i = 0; i < number.length(); i++)
		{
			list[i] = int(number[i]) - 48;
		}
		return list;
	}

	//Input: int list , degree
	//Output: int List where each index has result of operation to the degree
	//Example: list={1,2,4},degree=3 RETURNS list={1,8,64}
	int* power(int* list,int degree)
	{
		for (int i = 0; i < degree; i++)
		{
			int temp = 1;
			for (int j = 0; j < degree; j++)
			{
				temp *= list[i];
			}
			list[i] = temp;
		}
		return list;
	}

	//get Armstrong Sum from the Powered List
	int getArmstrongSum(int* number, int degree)
	{
		int sum = 0;
		for (int i = 0; i < degree; i++)
			sum += number[i];

		return sum;
	}


	bool getArmstrongNumber(int input)
	{
		this->number = this->toIntList(to_string(input));
		this->number = this->power(number, to_string(input).length());

		if (input == getArmstrongSum(this->number, to_string(input).length()))
			return true;

		return false;
	}


};

ArmstrongNumber::ArmstrongNumber()
{
	this->number = NULL;
}

ArmstrongNumber::~ArmstrongNumber()
{
	delete[] this->number;
}
int main()
{
	int number = 371;
	int start = 100;
	int range = 10000;
	ArmstrongNumber obj;
	obj.isArmstrongNumber(number);
	obj.printArmstrongNumbers(start,range);
	
}

