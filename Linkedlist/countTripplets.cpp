//https://practice.geeksforgeeks.org/problems/87f12e5c728d69a5322634776b54c75897d14daa/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    unordered_map<int,int> mp;
    Node* temp = head;
    int a = 0;
    while(temp)
    {
        mp[temp->data]=a;
        temp=temp->next;
        a++;
    }
    Node* i = head;int cnt = 0;
    a=0;int b = 0;
    while(i)
    {
        Node* j = i->next;b=a+1;
        while(j)
        {
            if(mp.find(x-(i->data+j->data))!=mp.end()&&mp[x-(i->data+j->data)]>b)
                cnt++;
            b++;
            j=j->next;
        }
        a++;
        i=i->next;
    }
    return cnt;
    // code here.
} 