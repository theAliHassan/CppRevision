#include<iostream>
#include<exception>
using namespace std;

void ReverseString(std::string &str)
{
	if (str.empty()) throw invalid_argument("Empty String");
	if (str.size() == 1) return;

	int right = str.size() - 1;
	for (int i = 0; i < (str.size()/2); i++) 
		swap(str[i], str[right - i]); //swaps left with right index till middle. 
}
bool isPalindrome(std::string str)
{
	if (str.empty()) throw invalid_argument("Empty String");
	if (str.size() == 1) return true;

	int Palindromeright = str.size() - 1;
	for (int i = 0; i < (str.size() / 2); i++)
		if (str[i] != str[Palindromeright - i]) //matches left with right index till middle. 
			return false;
	return true; 
}

int main()
{
	try
	{
		std::string str = "1 2 3 4 5";
		ReverseString(str);
		cout << str << endl;

		str = "ANNA";
		cout << isPalindrome(str) << endl;
		return 0;
	}
	catch (const std::exception& e)
	{
		cerr << "Exception caught: " << e.what() << endl;
		return 1; // Exit with error status
	}
}
