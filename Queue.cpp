#include<iostream>
#include<cassert>
using namespace std;

void runTests();
struct Node
{
	Node* link;
	int data;

	Node(int data)
	{
		this->link = nullptr;
		this->data = data;
	}
};
class queue
{
public:
	//constructor
	queue() 
	{
		this->front = nullptr;
		this->rear = nullptr;
		this->size = 0;
	}
	//destructor
	~queue() 
	{
		this->destroyQueue();
	}
	//member functions
	void enqueue(int number)
	{
		this->pushQueue(number);
	}
	int dequeue()// return -1 if queue empty
	{
		int temp = this->popQueue();
		if (temp != -1)
			return temp;
		else
			return -1; // queue empty
	}
	int getFront()
	{
		int temp = this->queueFront();
		return temp;
	}
	int getRear()
	{
		int temp = this->queueRear();
		return temp;
	}
	int getSize()
	{
		int temp = this->size;
		return temp;
	}
	void displayQueue()
	{
		cout << "======================\n";
		this->printQueue();
		cout << "\n======================\n";
	}


private:
	Node* front;
	Node* rear;
	int size;

	bool isEmpty()
	{
		if (this->front == nullptr)
			return true;
		return false;
	}
	void pushQueue(int number)
	{
		Node* newNode = new Node(number);
		if (!this->isEmpty())//
		{
			this->rear->link = newNode;
			this->rear = newNode;
			this->size++;
			return;
		}
		this->front = newNode;//initialize queue
		this->rear = newNode;
		this->size++;
		return;
	}
	int popQueue()
	{
		if (!this->isEmpty())
		{
			Node* temp = this->front;
			int data = temp->data;
			this->front = this->front->link;
			delete temp;
			this->size--;
			return data;
		}
		return -1;
	}
	void destroyQueue()
	{
		Node* temp = this->front;
		while (temp != nullptr)
		{
			this->front = temp->link;
			delete temp;
			temp = this->front;
			this->size--;
		}
		return;
	}
	void printQueue()
	{
		Node* temp = this->front;
		while (temp != nullptr)
		{
			cout << temp->data << "  ";
			temp = temp->link;
		}
		return;
	}
	int queueFront()
	{
		Node* temp = this->front;
		return temp->data;
	}
	int queueRear()
	{
		Node* temp = this->rear;
		return temp->data;
	}
};


int main()
{
	runTests();
	return 0;
}

void runTests()
{
	// Create a queue object
	queue myQueue;

	// Test Enqueue and GetSize
	myQueue.enqueue(10);
	myQueue.enqueue(20);
	myQueue.enqueue(30);

	assert(myQueue.getSize() == 3);

	// Test Dequeue, QueueFront, and QueueRear
	assert(myQueue.dequeue() == 10);
	assert(myQueue.getFront() == 20);
	assert(myQueue.getRear() == 30);


	// Test Dequeue on an empty queue
	myQueue.dequeue();
	myQueue.dequeue();
	assert(myQueue.dequeue() == -1);

	// Test DisplayQueue
	myQueue.displayQueue(); // Check manually if the queue is displayed correctly


	// Extreme Test Cases

	// Enqueue a large number of elements
	for (int i = 0; i < 10000; ++i)
	{
		myQueue.enqueue(i);
	}
	assert(myQueue.getSize() == 10000);

	// Dequeue all elements
	for (int i = 0; i < 10000; ++i)
	{
		assert(myQueue.dequeue() == i);
	}
	assert(myQueue.getSize() == 0);

	// Enqueue and Dequeue large numbers
	for (int i = 0; i < 1000000; ++i)
	{
		myQueue.enqueue(i);
		assert(myQueue.dequeue() == i);
	}
	assert(myQueue.getSize() == 0);

	std::cout << "All tests passed successfully!" << std::endl;
}
