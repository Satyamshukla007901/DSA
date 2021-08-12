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
//Delete in BST
//Function for finding inorder succesor
Node* inorederSucc(Node* root)
{
    Node* curr = root;
    while(curr&&curr->left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}
//function for deleting the node
Node* deleteBST(Node* root,int key)
{
    if(key<root->data)
    {
        root->left = deleteBST(root->left,key);
    }
    else if(key>root->data)
    {
        root->right = deleteBST(root->right,key);
    }

    else{
        if(root->left==NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorederSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right,temp->data);
    }
    return root;
}
//Construct Binary Search tree from preorder Sequence
Node* constructBST(int preorder[],int* preorderIdx,int key,int min,int max,int n)
{
    if(*preorderIdx>=n){return NULL;}

    Node* root = NULL;
    if(key>min&&key<max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx+1;

        if(*preorderIdx<n)
        {
            root->left = constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n)
        {
            root->right = constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;
}
void preorder(Node* root)
{
    if(!root)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
    /*
        5
       / \
      1   7
       \
        3
       / \
      2   4
    */
    // Print Inorder
    inorder(root);
    cout<<endl;
    // int x;
    // cin>>x;
    // if(searchInBST(root,x)==NULL)
    // {
    //     cout<<"Key does'nt Exist"<<endl;
    // }
    // else
    // {
    //     cout<<"key Exist"<<endl;
    // }
    // root = deleteBST(root,x);
    // inorder(root);
    preorder(root);
    cout<<endl;
    int preorder1[] = {5,1,3,2,4,7};
    int n=6;
    int preorderIdx = 0;
    Node* root1 = constructBST(preorder1,&preorderIdx,preorder1[0],INT_MIN,INT_MAX,n);
    preorder(root1);
    cout<<endl;

}