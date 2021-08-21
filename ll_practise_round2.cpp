#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define fasio                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fori(i, a, b) for (int i = a; i < b; i++)
#define endl "\n"
#define elif else if
const ll INF = 1e17;
const ll NINF = (-1) * INF;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
};
void insert(DLLNode** head, int data)
{
    // allocate node
    DLLNode* temp = new DLLNode();
 
    // put in the data
    temp->data = data;
    temp->next = temp->prev = NULL;
 
    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
Node *addOne(Node *head)
{
    if (head->next == NULL)
    {
        head->data += 1;
        return head;
    }
    else
    {
        Node *first = head;
        Node *sec = head;
        while (first->next)
        {
            if (first->data != 9)
                sec = first;
            first = first->next;
        }
        if (first->data == 9 && sec != NULL)
        {
            sec->data += 1;
            first = sec->next;
            while (first)
            {
                first->data = 0;
                first = first->next;
            }
        }
        else
        {
            first->data += 1;
        }
        return head;
    }
}
//Commented code for Circular must only
Node *deleteNode(Node *head, int key)
{
    if (!head)
        return NULL;
    // if(head->next==head)
    // {
    //     if(head->data==key)
    //         return NULL;
    //     else
    //         return head;
    // }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    while (head->data == key)
    {
        head = head->next;
    }
    temp = head;
    Node *prev = temp;
    while (temp)
    {
        if (temp->data == key)
        {
            if (temp->next != NULL)
                prev->next = temp->next;
            else
                prev->next = NULL;
        }
        prev = temp;
        temp = temp->next;
    }
    // temp=head;
    // while(temp->next)
    // {
    //     temp=temp->next;
    // }
    // temp->next=head;
    return head;
    // Write your code here.
}
//Reverse a Double Linked List
struct Node *reverseDLL(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *nxt;
    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        curr->prev = nxt;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
//Find pair with a given sum in a doubly linked list
//Time Limit Exceeded
//O(n^2)
//Not an optimised Approach
bool findPair1(Node *head, int k)
{
    Node *i = head;
    // Node* temp = head;
    // while(temp->next)
    // {
    //     temp=temp->next;
    // }
    while (i)
    {
        Node *lo = i->next;
        while (lo)
        {
            int sum = (i->data) + (lo->data);
            // int sum2 = (i->data)+(hi->data);
            if (k == sum)
                return true;
            lo = lo->next;
        }
        i = i->next;
    }
    return false;
    // Write your code here.
}
//Optimised Approach
//two pointer technique
//TC-> O(n)
bool findPair(Node *head, int k)
{
    Node *low = head;
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    Node *high = temp;
    while (low != high && high->next != low)
    {
        int sum = low->data + high->data;
        if (sum == k)
            return true;
        else if (sum < k)
            low = low->next;
        else if (sum > k)
            high = high->prev;
    }
    return false;
}

//3 Sum 2 Pointer Technique in Doubly Linked List
int countTriplets(DLLNode *head, int x)
{
    DLLNode* i = head;
    DLLNode* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    
    int ans=0;
    while(i)
    {
        // cout<<"outer"<<endl;
        int count=0;
        DLLNode* lo = i->next;
        DLLNode* hi = temp;
        while(lo&&hi&&lo!=hi&&hi->next!=lo)
        {
            // cout<<"Inner"<<endl;
            int sum =  (lo->data) + (hi->data);
            // cout<<"i = "<<" "<<i->data<<endl;
            // cout<<sum<<" "<<x-(i->data)<<endl;
            if(sum==(x-(i->data)))
            {
                // cout<<"Increement"<<endl;
                count++;
                lo=lo->next;
                hi=hi->prev;
                // break;
            }
            else if(sum>(x-(i->data)))
                hi=hi->prev;
            else
                lo=lo->next;
        }
        ans+=count;
        i=i->next;
    }
    return ans;

    // WRITE YOUR CODE HERE
}
void printL(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
struct node{
    int data;
    struct node* next;
    struct node* prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
//rotate doubly linkedlist by P nodes
struct node* update(struct node*start,int p)
{
    if(!start)
        return NULL;


    struct node* temp = start;
    struct node* prev = start;
    int count = 0;
    while(count!=p)
    {
        if(count!=p-1)
            prev=prev->next;
        count++;
        temp=temp->next;
    }
    struct node* end = start;
    while(end->next)
    {
        end=end->next;
    }
    end->next = start;
    start->prev = end;
    temp->prev = NULL;
    start = temp;
    prev->next = NULL;

    return start;
    //Add your code here
}
int main()
{
    // Node *head = NULL;
    // Node *temp1 = new Node(1);
    // head = temp1;
    // Node* temp2 = new Node(2);
    // Node* temp3 = new Node(3);
    // Node* temp4 = new Node(4);
    // Node* temp5 = new Node(5);
    // head->next=temp2;
    // temp2->next=temp3;
    // temp3->next=temp4;
    // temp4->next=temp5;
    // temp5->next=head;
    // head->next = head;
    // head = deleteNode(head, 1);
    // printL(head);
     DLLNode* head = NULL;
 
    // insert values in sorted order
    insert(&head, 91);
    insert(&head, 88);
    insert(&head, 33);
    insert(&head, 7);
    // insert(&head, 5);
    // insert(&head, 4);
    // insert(&head, 3);
    // insert(&head, 2);
    // insert(&head, 1);
 
    int x = 40;
 
    cout << "Count = "
         << countTriplets(head, x);
}