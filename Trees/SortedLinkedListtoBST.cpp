//https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    TNode* sortedListToBST(LNode *head) {
        //This Question is done by Divide and Conqueuer Technique
        if(head==NULL) return NULL;
        if(head->next==NULL) return new TNode(head->data);
        LNode *slow = head;
        LNode *fast = head;
        LNode * p = NULL;
        while(fast&&fast->next)
        {
            p=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TNode* root = new TNode(slow->data);
        p->next = NULL;
        root->left = sortedListToBST(head);
        if(slow->next)
            root->right = sortedListToBST(slow->next);
        return root;
        //code here
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends