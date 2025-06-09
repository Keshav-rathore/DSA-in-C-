#include<iostream>
using namespace std;

class node{
    public:
     int data;
     node* left;
     node* right;

    node(){
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class tree{
    public:
     node* root;

    tree(){
        root = nullptr;
    }

    void insertionLeft(int x){
        node* newnode = new node(x);
        if(root == nullptr) {
            root = newnode;
            return;
        }
        node* temp = root;
        while(temp->left!= nullptr){
            temp = temp->left;
        }
        temp->left = newnode; 
    }
    
    void insertionRight(int x){
        node* newnode = new node(x);
        if(root == nullptr) {
            root = newnode;
            return;
        }
        node* temp = root;
        while(temp->right!= nullptr){
            temp = temp->right;
        }
        temp->right = newnode; 
    }

   
};
int main(){
return 0;
}