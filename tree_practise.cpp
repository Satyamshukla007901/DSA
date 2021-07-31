#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x)
    {
       data = x;
       left = NULL;
       right = NULL; 
    }
    
};
void preorder(struct Node* root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root)
{
    if(!root)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct Node* root)
{
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int32_t main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    //preorder traversal
    preorder(root);
    cout<<endl;

    //inorder traversal
    inorder(root);
    cout<<endl;

    //postorder traversal
    postorder(root);
    cout<<endl;
}
