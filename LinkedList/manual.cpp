#include <iostream>
using namespace std;

// define a node class
class Node
{
    // properties of Node class
public:
    int data;
    Node *next;

    // default Constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // parameter Constructor
    Node(int n)
    {
        data = n;
        next = NULL;
    }

    // Note: we can use arrow operator('->') in case of name conflict like instead of n we rename our argument as data then we use this->data(Node class property) = data(we take as argument)
};

int main()
{
    // using default constructor
    Node first = Node();
    // it create a object with name first for class Node. Assume like int x; Node is variable type, first is variable name. and property data(not intialized) and next with NULL Value.
    first.data = 10;

    // using parameter constructor
    Node second = Node(20);
    // create a object with data = 10 , next = NULL;

    // to form a connection between first Node and Second node we require then address so we use ampersand operator/ address operator (&)
    cout << "Address of First node" << &first << endl;   // 0xb7425ff750
    cout << "Address of Second node" << &second << endl; // 0xb7425ff740

    // As we got address now we interconnect them with help of next property
    first.next = &second;

    cout << first.data << " - " << first.next << endl;
    cout << second.data << " - " << second.next << endl;
    // output ->10 - 0x90295ffdc0
    //        ->20 - 0

    /*
    In this code we use stack memory allocation
    Problems
    // Nodes are created on the stack, so they are automatically destroyed when main() ends.
    // This is fine for 2–3 nodes, but not scalable for 100+ nodes.We need a loop and dynamic memory allocation (using `new`) to handle larger linked lists.
    */
    return 0;
}