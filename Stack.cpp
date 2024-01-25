#include <iostream>
using namespace std;

struct Node {
    Node* link;
    int data;

//Default Constructor
    Node():link(nullptr),data(0){}
//Parametrized Constructor
    Node(int data):link(nullptr),data(data){}
};
class Stack
{
private:
    Node* stackTop;
    int stackSize;
    // member functions -Empty Body
    void pushStack(int x)
    {

    }
    int popStack()
    {
        return 1;
    }
    bool isEmpty() const
    {
        if (this->stackTop == nullptr)
            return true;
        return false;
    }
    void destroyStack()
    {
        
    }
public:
    Stack()
    {
        this->stackTop=nullptr;
        this->stackSize=0;
    }
    ~Stack()
    {

    }
    //user member functions -Empty Body
    void push(int x)
    {

    }
    int pop()
    {
        return 1;
    }
    int getSize()
    {
        return this->stackSize;
    }
    int getStackTop()
    {
        return -1;
    }
};


