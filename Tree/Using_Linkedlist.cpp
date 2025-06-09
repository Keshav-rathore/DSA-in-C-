#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class tree
{
public:
    node *root;

    tree()
    {
        root = nullptr;
    }


    void preOrder(node* node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
        return;
    }

    void inOrder(node *node)
    {
       if(node == nullptr) return;
       inOrder(node->left);
       cout<<node->data<<" ";
       inOrder(node->right);
    }

    void postOrder(node *root)
    {
        if (root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
        return;
    }

    bool search(node* rnode, int x){
        if(rnode == nullptr) return false;
        if(x == rnode->data) return true;
        return search(rnode->left,x)|| search(rnode->right,x);
    }
};
int main()
{
    tree t;
    t.root = new node(1);
    t.root->left = new node(2);
    t.root->right = new node(3);
    t.root->left->left = new node(4);
    t.root->left->right = new node(5);
    t.root->right->right = new node(6);

    t.preOrder(t.root);
    cout<<endl;
    t.inOrder(t.root);
    cout<<endl;
    t.postOrder(t.root);
    cout<<t.search(t.root,4);
    return 0;
}