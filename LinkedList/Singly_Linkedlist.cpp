#include <iostream>
#include <stack>
using namespace std;

class node{
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
class Linkedlist{
public:
    node *head;

    // Constructor
    Linkedlist(){
        head = NULL;
    }

    // insert element at head
    void insertBegin(int n){  
        node *temp = new node(n); 
        temp->next = head;        
        head = temp;              
    }

    // insert element at provided index
    void insertIdx(int n, int idx){
        int length = size();
        if (idx == 0){
            insertBegin(n);
            return ;
        }else if(head == NULL && idx>0){
            cout<<"Invalid index"<<endl;
        }else if(idx<=length){
            node *temp = head;
            for (int i = 0; i < idx - 1; i++){
                temp = temp->next;
            };
            node *newtemp = new node(n);
            newtemp->next = temp->next;
            temp->next = newtemp;
        }   
    }

    // Add element to tail
    void insertEnd(int n){
        node *temp = head;
        while (temp->next != NULL){
          temp = temp->next;
        }
        node *newtemp = new node(n);
        temp->next = newtemp;
    }

    //return length of linkedlist
    int size(){
        int count = 0;
        node *temp = head;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    //delete head element
    void deleteBegin(){
        node *temp = head;
        head = temp->next;
        delete temp;
    }

    //Delete from provided index
    void deleteIndx(int idx){
        node *temp = head;
        for (int i = 0; i < idx - 1 && temp->next != NULL; i++){ 
            temp = temp->next;
        }
        node *todelete = temp->next;  
        temp->next = temp->next->next;
        delete todelete;  
    }

    //Delete tail Element
    void deleteEnd(){
        node *temp = head;
        while (temp->next->next != NULL)
        { 
            temp = temp->next;
        }
        node *todelete = temp->next;
        temp->next = NULL; 
        delete todelete;   
    }

    //Print Element
    void print(){
        node *temp = head; 
        while (temp != NULL)
        {
            cout << temp->data << ' ';
            temp = temp->next;        
        }
        cout << endl;
    }
    
    //Find Element
    int findElement(int target){
        node* temp = head;
        int index = 0;
        while(temp != NULL ){
            if(temp->data == target){
                return index ;
            }
            temp = temp->next;
            index++;   
        }
        return -1;
    }

    // Reverse Linked List
    void reverselist(){
        node* temp = head;
        stack<int> st;
        while(temp != NULL ){
            st.push(temp->data);
            temp = temp->next;
        }
        node* upd = head;
        while(upd != NULL ){
            upd->data = st.top();
            st.pop();
            upd = upd->next;
        }
    }

    // Detect Cycle in Linked List
    bool detectcycle(){
        node* slow = head;
        node* fast = head;
        while(fast != NULL && fast->next !=NULL){
           slow = slow->next;
           fast = fast->next->next;
           if(slow == fast){
                return true;
            }
        }
        return false;
    }
    
    // return middle element(2nd middle in case n%2==0)
    int middleelement(){
    int length = size();
    int middle = length / 2;
    node* temp = head;
    for(int i = 0; i < middle; i++){
        temp = temp->next;
    }
    return temp->data;
    }

    // Remove Duplicates from sorted linkedlist
    void removeduplicate(){
        node* current = head;
        while(current !=NULL && current->next != NULL){
            if(current->data == current->next->data){
                node* todelete = current->next;
                current->next = current->next->next;
                delete todelete;
            }else{
                current = current->next;
            }
        }
    }

    //Check for palindrome or not
    bool ispalindrome() {
        node* temp = head;
        stack<int> st;
        int length = size();
        int middle = length / 2;
        for (int i = 0; i < middle; i++) {
         st.push(temp->data);
         temp = temp->next;
        }
        if (length % 2 != 0) {
        temp = temp->next;
        }
        while (temp != NULL) {
        if (st.top() != temp->data) {
            return false;
        }
        st.pop();
        temp = temp->next;
        }
         return true;
    }

    
};

int main()
{
    Linkedlist l1 = Linkedlist();
    l1.insertBegin(10);
    l1.insertEnd(20);
    l1.insertEnd(30);
    l1.insertEnd(30);
    l1.insertEnd(50);
    l1.insertEnd(50);
    l1.insertEnd(70);
    l1.print();
    l1.removeduplicate();
    l1.print();
    return 0;
}