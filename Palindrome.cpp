#include<iostream>
using namespace std;

// ---------------- FUNCTION DECLARATION ------------------
bool inputValidation(string text);
bool isPalindrome(string text);
bool checkPalindrome(string text);

// ---------------- DRIVER FUNCTION ----------------------
int main()
{
	string text = "ANNA";
	cout<<isPalindrome(text);
}

// -----------------FUNCTION DEFINATIONS------------------

bool inputValidation(string text)
{
	//CHECKS IF INPUT IS A STRING
	if (text.length() <= 0)
		return false;
	return true;
}
bool isPalindrome(string text)
{	
	if (!inputValidation(text))
		return false;
	if (checkPalindrome(text))
		return true;
	return false;
}
bool checkPalindrome(string text)
{
	for (int i = 0, j = text.length() - 1; i <= j; i++, j--)
		if (text[i] != text[j])
			return false;
	return true;
}

