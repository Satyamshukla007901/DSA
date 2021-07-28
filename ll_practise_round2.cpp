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
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
Node *addOne(Node *head)
{
    if(head->next==NULL)
    {
        head->data+=1;
        return head;
    }
    else
    {
        Node *first = head;
        Node *sec = head;
        while(first->next)
        {
            if(first->data!=9)
                sec=first;
            first=first->next;
        }
        if(first->data==9&&sec!=NULL)
        {
            sec->data+=1;
            first=sec->next;
            while(first)
            {
                first->data=0;
                first=first->next;
            }
        }
        else{
            first->data+=1;
        }
        return head;
    }

}
//Commented code for Circular must only
Node* deleteNode(Node* head, int key) 
{
    if(!head)
        return NULL;
    // if(head->next==head)
    // {
    //     if(head->data==key)
    //         return NULL;
    //     else
    //         return head;
    // }
    Node* temp = head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next = NULL;
    while(head->data==key)
    {
        head=head->next;
    }
    temp=head;
    Node* prev = temp;
    while(temp)
    {
        if(temp->data==key)
        {
            if(temp->next!=NULL)
                prev->next=temp->next;
            else
                prev->next=NULL;
        }
        prev=temp;
        temp=temp->next;
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
int main()
{
    Node* head = NULL;
    Node* temp1 = new Node(1);
    head = temp1;
    // Node* temp2 = new Node(2);
    // Node* temp3 = new Node(3);
    // Node* temp4 = new Node(4);
    // Node* temp5 = new Node(5);
    // head->next=temp2;
    // temp2->next=temp3;
    // temp3->next=temp4;
    // temp4->next=temp5;
    // temp5->next=head;
    head->next = head;
    head=deleteNode(head,1);
    printL(head);
}