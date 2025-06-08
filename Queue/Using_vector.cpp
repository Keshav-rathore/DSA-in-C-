#include<iostream>
using namespace std;

class queue{
    static const int n = 10;
    int array[n];
    int front ;
    int rear ;
    
    public:
     queue(){
        front = -1;
        rear = -1;
     }

     //Enqueue
     void enque(int x){
        if(front == -1 && rear == -1){
            front = rear = 0;
            array[front] = x;
            return;
        }else if( rear == n-1) cout<<"Overflow Condition"<<endl;
        else array[++rear] = x;
     }

     void deque(){
        if(front == rear) {
            front = rear = -1;
            return;
        }
        front ++;
     }

     void Front(){
        if(front == -1){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<array[front]<<endl;
     }
     
     void Rear(){
        if(front == -1){
            cout<<"Queue is Empty"<<endl;
            return;
        }
       cout<< array[rear]<<endl;
     }

     void display(){
        for(int i=front;i<=rear;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
     }

     bool isEmpty(){
        if(front == -1 || front>rear) return true;
        else return false;
     }

     bool isFull(){
        return (rear == n-1);
     }

};

int main(){

   

    return 0;
}