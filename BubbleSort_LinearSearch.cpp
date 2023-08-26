#include<iostream>
using namespace std;
 
int* getRandomList(int size)
{
	srand(12345);
	int* list = new int[size];
	for (int i = 0; i < size; i++)
	{
		list[i] = rand();
	}
	return list;
}
int* sortlist(int* list,int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (list[i] < list[j])
				swap(list[i], list[j]);
	return list;
}
void printList(int* list, int size)
{
	for (int i = 0; i < size; i++)
		cout << list[i] << "  ";
}
bool searchList(int* list, int size, int key)
{
	int i = 0;
	if (key > list[size / 2])
		i = size / 2;

	for (; i < size; i++)
		if (key == list[i])
			return true;

	return false;
}
int main()
{
	int* list = getRandomList(10);
	list = sortlist(list,10);
	cout << searchList(list, 10, 25795) ;
	delete[] list;
}