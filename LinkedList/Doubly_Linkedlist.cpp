#include<iostream>
using namespace std;

class node{
    public:
      int data;
      node* prev;
      node* next;

    node(){
        data = 0;
        prev = NULL;
        next = NULL;
    }

    node(int n){
        data = n;
        prev = NULL;
        next = NULL;
    }

};

class linkedlist{
    public:
     node* head;
     node* tail;

    linkedlist(){
        head = NULL;
        tail = NULL;
    }

    //Insert at Begin
    void insertBegin(int n){
        node* temp = new node(n);
        if(head == NULL){
            head = tail = temp;
            return;
        }
        head->prev = temp;
        temp->next = head;
        head = temp;
    }

    //Insert at Index
    void insertIndex(int idx , int n){
        node* temp = head;
        for(int i=0;i<idx;i++){
            if(temp == NULL) return;
            temp = temp->next;
        }
        node* temp2 = new node(n);
        temp2->prev = temp;
        temp2->next = temp->next;
        if(temp->next != NULL){
             temp->next->prev = temp2;
        }
        temp->next = temp2;
    }

    //Insert at tail
    void insertEnd(int n){
        node* newnode = new node(n);
        if(head == NULL){
            head = tail = newnode;
        }else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    //print all nodes
    void print(){
        node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // delete Head
    void deleteHead(){
        if (head == NULL) return;
        node* temp = head;
        if(head->next == NULL) head = NULL;
        else{
        head = head->next;
        head->prev = NULL;
        }
        delete temp;
    }
    
    //delete tail
    void deleteTail(){
        if(head == NULL) return;
        else if(head->next == NULL){
            delete head;
            head = tail = NULL;
        }
        else{
            node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    //delete at index
    void deleteIndex(int n){
        node* temp = head;
        int i=0;
        while(i<=n && temp != NULL){
            temp = temp->next;
        } 
        node* todelete = temp;
        temp->next = temp->next->next;
        temp->next->prev = temp;

        delete temp;

    }

    //print reverse
    void printreverse(){
        node* temp = tail;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }

    // Reverse list by swaping prev and next
    void reverselist(){
        node* temp = head ;
        while(temp!=NULL){
            node* temp1 = temp->next;
            temp->next = temp->prev;
            temp->prev = temp1;

            temp = temp->prev ;
        }   
        
        node* temp2 = head;
        head = tail;
        tail = temp2;
    }

    int size(){
        int count = 0;
        node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isCircular(){
        node* temp = head->next;
        while(temp != NULL && temp !=head){
            temp = temp->next;
        }
        return (temp == head);
    }

};
int main(){
    linkedlist l1 = linkedlist();
    l1.insertBegin(10);
    l1.insertEnd(20);
    l1.insertEnd(30);
    l1.insertEnd(40);
    l1.insertEnd(50);
    l1.insertIndex(3,60);
    l1.print();
    cout<<l1.size();

return 0;
}