#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // parameter constructor
    node(int n)
    {
        data = n;
        next = NULL;
    }
};
class Linkedlist
{
public:
    node *head;

    // Constructor
    Linkedlist()
    {
        head = NULL;
    }

    void insertBegin(int n)
    {
        node *temp = new node(n); // dynamically create new object of node. temp value is the address of new node.
        temp->next = head;        // to access the value we use asterik operator(*)  temp->next is equal to  *(temp).next
        head = temp;              // update the head new address
    }

    // By Convention we treat linked list as 0 indexed based
    void insertIdx(int n, int idx)
    {
        int length = size();
        if (idx == 0)
            insertBegin(n);
        if (idx <= length)
        {
            node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            node *newtemp = new node(n);
            newtemp->next = temp->next;
            temp->next = newtemp;
        }
        else
        {
            cout << "Invalid index";
        }
    }

    void insertEnd(int n)
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *newtemp = new node(n);
        temp->next = newtemp;
    }

    int size()
    {
        int count = 0;
        node *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteBegin()
    {
        node *temp = head;
        head = temp->next;
        delete temp;
    }

    void deleteIndx(int idx)
    {
        node *temp = head;
        for (int i = 0; i < idx - 1 && temp->next != NULL; i++)
        { // iterate to previous node idx
            temp = temp->next;
        }
        node *todelete = temp->next;   // node to me deleted
        temp->next = temp->next->next; // update the value of previous node to next to next address
        delete todelete;               // free the memory of todelete node to prevent Memory link
    }

    void deleteEnd()
    {
        node *temp = head;
        while (temp->next->next != NULL)
        { // iterate to second last node
            temp = temp->next;
        }
        node *todelete = temp->next;
        temp->next = NULL; // disconnect last node
        delete todelete;   // free memory to prevent memory leak
    }

    void print()
    {
        node *temp = head; // create a pointer with name temp to store the address of node type variable and give assign it with head address
        while (temp != NULL)
        {
            cout << temp->data << ' '; // print the node value
            temp = temp->next;         // update the temp to address of next node
        }
        cout << endl;
    }

    // Reverse Linked List
    // Find Element in Linked List
    // Find Middle Element
    // Detect Cycle in Linked List
    // Remove Duplicates (for sorted or unsorted list)
    // Merge Two Sorted Linked Lists
    // Check if Linked List is a Palindrome
    
};

int main()
{
    // create a linkedlist
    Linkedlist l1 = Linkedlist();
    l1.insertBegin(10);
    l1.insertBegin(20);
    l1.insertBegin(30);
    l1.insertBegin(40);
    l1.print();

    l1.insertIdx(50, 2);
    l1.print();

    l1.insertEnd(60);
    l1.print();
    return 0;
}