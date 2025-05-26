#include<iostream>
using namespace std;

class node{
    public:
     int data;
     node* prev;
     node* next;

    node(int n){
        data = n;
        prev = NULL;
        next = NULL;
    };
      
};

class linkedlist{
    public:
     node* head;

    linkedlist(){
        head = NULL;
    }

    //print Linkedlist
    void print(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    //Insert at beginning
    void insertBegin(int n){
        node* temp = new node(n);
        temp->next = head;
        temp->prev = head->prev;
        head = temp;
    };

    //Insert at Index
    void insertIndex(int n, int idx){
        node* temp = head;
        for(int i=0;i<idx;i++){
            temp = temp->next;
        }
        node* temp2 = new node(n);
        temp2->next = temp->next;
        temp->next  = temp2;
    }

    //Insert at End

    //delete at beginning

    //delete at Index

    //delete at end

    //Reverse the Linkedlist

    //Find Element in Linkedlist

    //Get length of Linkedlist


    //Find middle Element

    //Remove Duplicates Element

};

int main(){

    linkedlist l1 = linkedlist();

    l1.insertBegin(10);
    l1.insertBegin(20);
    l1.insertBegin(30);
    l1.print();
    l1.insertIndex(20,1);
    l1.print();

return 0;
}