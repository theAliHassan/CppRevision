#include<iostream>
using namespace std;

class ReverseList
{
public:
	ReverseList();
	ReverseList(int size);
	ReverseList(const ReverseList& obj);
	~ReverseList();

	void reverseList();
	void fillListRandomly();
	void setList();
	int* getList();
	void printList();

private:
	bool isInputValid();
	int* list;
	int size;
};

int main()
{
	ReverseList list(50);
	list.fillListRandomly();
	list.printList();
	cout << endl;
	list.reverseList();
	list.printList();
}

//============= DEFAULT CONSTRUCTOR ============
ReverseList::ReverseList()
{
	this->list = nullptr;
	this->size = -1;
	if (!this->isInputValid())
		return;
}
//============= PARAMETRIZED CONSTRUCTOR ============
ReverseList::ReverseList(int size)
{
	this->size = size;
	this->list = new int[size];
	if (!this->isInputValid())
		return;
}
//============= COPY CONSTRUCTOR ============
ReverseList::ReverseList(const ReverseList& obj)
{
	this->size = obj.size;
	this->list = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->list[i] = obj.list[i];
}
//============= DESTRUCTERER ============
ReverseList::~ReverseList()
{
	delete[] this->list;
	this->size = -1;
}

//============CLASS FUNCTION DEFINATIONS================
void ReverseList::reverseList()
{
	ReverseList obj(*this);
	int temp = this->size - 1;
	for (int i = 0; i < this->size; i++)
		swap(obj.list[i], this->list[temp - i]);
}
void ReverseList::fillListRandomly()
{
	//fills list with random numbers <=100
	for (int i = 0; i < this->size; i++)
		this->list[i] = rand() % 100;
}
void ReverseList::setList()
{
	cout << "ENTER VALUES: ";
	for (int i = 0; i < this->size; i++)
		cin >> this->list[i];
}
int* ReverseList::getList()
{
	int* temp = new int[this->size];
	for (int i = 0; i < this->size; i++)
		temp[i] = this->list[i];
	return temp;
}
void ReverseList::printList()
{
	for (int i = 0; i < this->size; i++)
		cout << this->list[i] << " ";
}
bool ReverseList::isInputValid()
{
	if (this->size <= 0)
		return false;
	if (this->list == nullptr)
		return false;
	return true;
}