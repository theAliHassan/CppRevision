#include <iostream>
using namespace std;

struct Node {
    Node* link;
    int data;

    // Default constructor
    Node() : link(nullptr), data(0) {}

    // Parameterized constructor
    Node(int data) : link(nullptr), data(data) {}

    // Destructor
    ~Node() {
        // Free any memory allocated by this node, if any
        delete link;
    }
};