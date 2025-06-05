#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int x){
        data = x;
        next = nullptr;
    }
};

class Queue{
    public:
    node* front;
    node* rear;

    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    //Enqueue
    void enqueue(int x){
      node* temp = new node(x);
      if(rear == nullptr) front =rear = temp;
      else{
        rear->next = temp;
        rear = temp;
      }
    }

    //Dequeue
    void dequeue(){
        if(front == nullptr) return;
        node* todelete = front;
        front = front->next;
        if(front == nullptr ) rear = nullptr;
        delete todelete;
    }

    //front
    void peek(){
        if(front!=nullptr) cout<<front->data<<endl;
    }

    //isempty
    bool isEmpty(){
        if(front == nullptr) return true;
        else return false;
    }

    //size
    int size(){
        int count = 0;
        node* temp = front;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    //display
    void display(){
        node* temp = front;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void clear(){
        node* temp = front;
        while(temp!=nullptr){
            node* todelete = temp;
            temp = temp->next;
            delete todelete;
        }
        front = rear = nullptr;
    }

};
int main(){

return 0;
}