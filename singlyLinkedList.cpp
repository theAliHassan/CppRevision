#include<iostream>
#include <cassert>
#include<limits>
using namespace std;

struct Node 
{
	//Data Members
	double number;
	Node* link;
	//Constructor 
	Node()
	{
		this->link = nullptr;
		this->number = -1;
	}
	Node(double number)
	{
		this->link = nullptr;
		this->number = number;
	}
};
class singlyLinkedList
{
public:
	singlyLinkedList()
	{
		this->head = nullptr;
		this->listLength = 0;
	}
	~singlyLinkedList()
	{
		this->destroyList();
	}
	//setter getter methods
	void setList(double number)
	{
		this->insert(number);
	}
	void getList()
	{
		cout << "=====================" << endl;
		this->printList();
		cout <<endl<< "=====================" << endl;
	}
	int getLength()
	{
		int temp = this->listLength;
		return temp;
	}
	// public member functions
	bool find_inList(double number)
	{
		return this->search(number);
	}
	bool delete_atEnd() // deletes the last node
	{
		if (!this->isEmpty())
		{
			Node* temp = this->head;
			Node* _temp = this->head;

			while (temp->link->link != nullptr)
				temp = temp->link; //traverse to second last node

			_temp = temp->link;
			temp->link = nullptr; // make second last node last
			delete _temp; // free last node memory
			this->listLength--;
			return true;
		}
		return false;
	}
	bool delete_atStart() // deletes the first node
	{
		if (!this->isEmpty())
		{
			Node* temp = this->head;
			if (this->head->link != nullptr) 
				this->head = this->head->link; // make head point to second node of the list.
			else
				this->head = nullptr; // if list has only one node
			delete temp;
			this->listLength--;
			return true;
		}
		return false;
	}
	bool delete_atFirst(double number)  // deletes the value at the first occurence only
	{
		if (this->search(number))
		{
			if (this->head->number == number)// if value at first node
				return this->delete_atStart();
		
			Node* temp = this->head;
			Node* _temp = this->head;
			while (temp != nullptr)
			{
				if (temp->link->link == nullptr) // if value at last node
					return this->delete_atEnd();

				if (temp->link->number==number)
				{
					_temp = temp->link;
					temp->link = temp->link->link;
					delete _temp;
					this->listLength--;
					return true;
				}
				temp = temp->link;
			}
		}
		return false;
	}
	bool delete_atAll(double number) // deletes the value at all occurences
	{
		while (this->delete_atFirst(number)); // deletes single occurence at a time in a loop till all deleted;
		return this->find_inList(number);
	}
private:
	//Data Members
	Node* head;
	int listLength;
	//member functions 
	bool isEmpty()
	{
		if (this->head == nullptr)
			return true;
		return false;
	}
	void insert(double number)
	{
		Node* newNode = new Node(number);
		if (this->isEmpty()) //initialize list
			this->head = newNode;
		else
		{
			Node* temp = this->head;
			while (temp->link != nullptr)			
				temp = temp->link;
			temp->link = newNode;//insert at end
		}
		this->listLength++;
		return;
	}
	bool search(double number)
	{
		if (!this->isEmpty())
		{
			Node* temp = this->head;
			while (temp != nullptr)
			{
				if (temp->number == number)
					return true;
				temp = temp->link;
			}
		}
		return false;
	}
	void printList()
	{
		if (!this->isEmpty())
		{
			Node* temp = this->head;
			while (temp != nullptr)
			{
				cout << temp->number << "  ";
				temp = temp->link;
			}
		}
		return;
	}
	void destroyList()
	{
		if (!this->isEmpty())
		{
			Node* temp = this->head;
			while (temp != nullptr) //delete all nodes iteratively
			{
				this->head = temp->link;
				delete temp;
				temp = this->head;
				this->listLength--;
			}
		}
		return;
	}
};


void runTest()
{
	// Test Case 1: Normal Case - Insertion and Print
	singlyLinkedList list1;
	list1.setList(10);
	list1.setList(20);
	list1.setList(30);
	assert(list1.getLength() == 3);
	list1.getList();

	// Test Case 2: Normal Case - Search
	assert(list1.find_inList(20));
	assert(!list1.find_inList(40));

	// Test Case 3: Normal Case - Deletion at End
	list1.delete_atEnd();
	assert(list1.getLength() == 2);
	list1.getList();

	// Test Case 4: Normal Case - Deletion at Start
	list1.delete_atStart();
	assert(list1.getLength() == 1);
	list1.getList();

	// Test Case 5: Normal Case - Deletion at First Occurrence
	list1.setList(20);
	list1.setList(30);
	list1.delete_atFirst(20);
	assert(list1.getLength() == 2);
	list1.getList();

	// Test Case 6: Normal Case - Deletion of All Occurrences
	list1.setList(20);
	list1.setList(20);
	list1.setList(30);
	list1.delete_atAll(20);
	assert(list1.getLength() == 2);
	list1.getList();

	// Test Case 7: Extreme Case - Empty List
	singlyLinkedList emptyList;
	assert(emptyList.getLength() == 0);
	assert(!emptyList.find_inList(10));
	assert(!emptyList.delete_atEnd());
	assert(!emptyList.delete_atStart());
	assert(!emptyList.delete_atFirst(10));
	assert(!emptyList.delete_atAll(10));

	// Test Case 8: Extreme Case - Insertion of Large Number of Elements
	singlyLinkedList largeList;
	for (int i = 0; i < 10000; ++i) {
		largeList.setList(i);
	}
	assert(largeList.getLength() == 10000);

	// Test Case 9: Extreme Case - Deletion at End from an Empty List
	singlyLinkedList emptyList2;
	assert(!emptyList2.delete_atEnd());

	// Test Case 10: Extreme Case - Deletion at Start from an Empty List
	singlyLinkedList emptyList3;
	assert(!emptyList3.delete_atStart());

	// Test Case 11: Extreme Case - Deletion at First Occurrence from an Empty List
	singlyLinkedList emptyList4;
	assert(!emptyList4.delete_atFirst(10));

	// Test Case 12: Extreme Case - Deletion of All Occurrences from an Empty List
	singlyLinkedList emptyList5;
	assert(!emptyList5.delete_atAll(10));

	// Test Case 13: Extreme Case - Search for Element in an Empty List
	singlyLinkedList emptyList6;
	assert(!emptyList6.find_inList(10));

	// Test Case 14: Extreme Case - Deletion of All Occurrences of a Non-Existing Element
	singlyLinkedList list2;
	list2.setList(10);
	list2.setList(20);
	list2.setList(30);
	assert(!list2.delete_atAll(40));

	// // Test Case 15: Edge Case - Maximum Double Value
	// singlyLinkedList edgeList1;
	// edgeList1.setList(DBL_MAX);
	// assert(edgeList1.find_inList(DBL_MAX));

	// // Test Case 16: Edge Case - Minimum Double Value
	// singlyLinkedList edgeList2;
	// edgeList2.setList(DBL_MIN);
	// assert(edgeList2.find_inList(DBL_MIN));

	std::cout << "All test cases passed successfully!" << std::endl;
}
int main() {
	
	runTest();
	return 0;
}



