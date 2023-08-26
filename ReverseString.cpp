#include<iostream>
#include<string>
using namespace std; 

string getReverseString(string input)
{
	if (input.length() <= 0)
		return "";
	string output=input;
	for (int i = input.length()-1,j=0; i >=0; i--,j++)
		output[i] = input[j];
	return output;
}
int main()
{
	cout << getReverseString("ALI");
}