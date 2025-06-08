#include<iostream>
using namespace std;

class stack{
    int array[10];
    int top;

    public:
    stack(){
     top = -1;
    }

    void push(int x){
        top++;
        array[top] = x;
    }

    void pop(){
        if(top == -1){
            cout<<"Already Empty";
        }
        top--;
    }

    void peek(){
        if(top == -1) cout<<"Stack is Empty";
        else cout<<array[top]<<endl;;
    }

    void Display(){
      if(top == -1 ) return;
       for(int i = 0; i <= top; i++){
        cout <<array[i] <<" ";
       }
       cout << endl;
    }

    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }

};

int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.Display();
    st.pop();
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.peek();
    st.Display();
    st.isEmpty();

return 0;
}