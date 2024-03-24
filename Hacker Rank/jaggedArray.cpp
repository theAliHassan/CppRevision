#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

void setSize(int& s){cin >> s;}
void setQuery(int& q){	cin >> q;}
vector<int> stringParser(const std::string& str)
{
	std::stringstream ss(str);
	vector<int> list;
	string tempstr;
	ss.clear();
	while(std::getline(ss,tempstr,' '))
	{
		std::stringstream temp(tempstr);
		int n=-1;
		if(temp>>n)
			list.push_back(n);
	}
	return list;
}
std::vector<vector<int>> populateJaggedArray(const int sizeJagged)
{
	std::vector<vector<int>> jaggedArray(sizeJagged);
	//input
	cin.ignore();
	for (int i = 0; i < sizeJagged; i++)//main loop 
	{
		//read first number and resize as per it and populate
		std::string str;
		std::getline(cin, str);
		vector<int> input = stringParser(str);
        for (int j = 0; j < input[0]; j++)
        {
            jaggedArray[i].push_back(input[j + 1]);
        }
	}
	return jaggedArray;

	// 	//test print
	// for (int i = 0; i < sizeJagged; i++)
	// {
	// 	for (int j = 0; j < jaggedArray[i].size(); j++)
	// 	{
	// 		cout<<jaggedArray[i][j]<<" ";
	// 	}
	// 	cout << endl;
	// }
}
vector<int> getQuery(int query, vector<vector<int>>& arr)
{
	vector<int> result;
	int x=-1,y=-1;
	for (int i = 0; i < query; i++)
	{
		cin>>x>>y;
		result.push_back(arr[x][y]);
	}
	return result;
}
void printQuery(vector<int>& result)
{
	for (int i = 0; i < result.size(); i++)
		cout<<result[i]<<endl;
	return;
}
int main()
{
	//  2 2
	//	3 1 5 4
	//	5 0 1 2 3 4
	//	0 1
	//	1 3
	//	5
	//	3

	// read query and size of arrays
	int sizeJagged = -1, query = -1;
	std::vector<vector<int>> list;
	setSize(sizeJagged);
	setQuery(query);
	list=populateJaggedArray(sizeJagged);
	vector<int> result=getQuery(query,list);
	printQuery(result);

	return 0;

}