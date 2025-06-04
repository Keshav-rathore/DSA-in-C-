#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class stack
{
public:
    node *top;

    stack()
    {
        top = nullptr;
    }

    void push(int x)
    {
        node *newnode = new node(x);
        newnode->next = top;
        top = newnode;
    }

    void pop()
    {
        if (top == nullptr)
            return;
        node *todelete = top;
        top = top->next;
        delete todelete;
    }

    int peek()
    {
        return top->data;
    }

    bool isEmpty()
    {
        if (top == nullptr)
            return true;
        else
            return false;
    }

    int size()
    {
        int count = 0;
        node *temp = top;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display()
    {
        node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void clear()
    {
        while (top != nullptr)
        {
            node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool search(int x)
    {
        node *temp = top;
        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main()
{
    stack s1;
    s1.push(10); 
    s1.push(20); 
    s1.push(30); 
    s1.push(40); 
    s1.push(50);
    s1.display();
    s1.pop();
    s1.display();
    cout<<s1.peek();


    return 0;
}