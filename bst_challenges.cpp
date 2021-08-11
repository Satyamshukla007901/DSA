#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left,*right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* insertBST(Node* root,int val)
{
    if(!root)
    {
        return new Node(val);
    }

    if(val<root->data)
    {
        root->left = insertBST(root->left,val);
    }
    else
    {
        root->right = insertBST(root->right,val);
    }
    return root;
}
void inorder(Node* root)
{
    if(!root)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//Search in BST
//Time Complexity is O(logN)
Node* searchInBST(Node* root,int key)
{
    if(!root)
        return NULL;
    
    if(root->data==key){
        return root;
    }
    if(key<root->data)
    {
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}
int32_t main()
{
    Node* root = NULL;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    //Print Inorder
    inorder(root);
    cout<<endl;
    int x;
    cin>>x;
    if(searchInBST(root,x)==NULL)
    {
        cout<<"Key does'nt Exist"<<endl;
    }
    else
    {
        cout<<"key Exist"<<endl;
    }
}