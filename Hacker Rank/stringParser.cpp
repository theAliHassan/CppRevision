#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cassert>
std::vector<int> stringParser(std::string str){
	std::stringstream ss(str);
	std::vector<int> numlist;
	int num;
	char temp;
	while (ss >> num){
		numlist.push_back(num);
		ss >> temp;
	}
	return numlist;
}
void testCase1() {
    std::string str = "1,2,3,4,5";
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    std::vector<int> result = stringParser(str);
    assert(result == expected);
    std::cout << "Test Case 1 Passed\n";
}
void testCase2() {
    std::string str = "";
    std::vector<int> expected = {};
    std::vector<int> result = stringParser(str);
    assert(result == expected);
    std::cout << "Test Case 2 Passed\n";
}
void testCase3() {
    std::string str = "10,20,30,40,50";
    std::vector<int> expected = { 10, 20, 30, 40, 50 };
    std::vector<int> result = stringParser(str);
    assert(result == expected);
    std::cout << "Test Case 3 Passed\n";
}
void testCase4() {
    std::string str = "100";
    std::vector<int> expected = { 100 };
    std::vector<int> result = stringParser(str);
    assert(result == expected);
    std::cout << "Test Case 4 Passed\n";
}
void testCase5() {
    std::string str = "1,2,3,4,5,";
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    std::vector<int> result = stringParser(str);
    assert(result == expected);
    std::cout << "Test Case 5 Passed\n";
}
void testCase6() {
    std::string str = "1,2,3,4,5,6,7,8,9,10";
    std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> result = stringParser(str);
    assert(result == expected);
    std::cout << "Test Case 6 Passed\n";
}
void runAllTestCases() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    testCase5();
    testCase6();
}
int main()
{
    runAllTestCases();
    return 0;
}
