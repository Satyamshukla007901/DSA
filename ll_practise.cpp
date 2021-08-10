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
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
int getCount(struct Node *head)
{
    struct Node *temp = head;
    int count = 0;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void create(struct Node *&head, int val)
{
    if (head == NULL)
    {
        struct Node *temp =
            (struct Node *)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = head;
        head = temp;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        struct Node *temp2 = (struct Node *)malloc(sizeof(struct Node));
        temp2->data = val;
        temp2->next = NULL;
        temp->next = temp2;
    }
}
struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    while (curr)
    {
        struct Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
    // code here
    // return head of reversed list
}
bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
    // your code here
}
int getMiddle(Node *head)
{
    if (head == NULL)
        return -1;
    int length = 0;
    struct Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        length++;
    }
    length /= 2;
    temp = head;
    while (length-- > 0)
    {
        temp = temp->next;
    }
    return temp->data;
    // Your code here
}
int getNthFromLast(struct Node *head, int n)
{
    int length = 0;
    struct Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        length++;
    }
    if (n > length)
        return -1;
    n = length - n;
    temp = head;
    while (n-- > 0)
    {
        temp = temp->next;
    }
    return temp->data;
}
void deleteNode(Node *del)
{
    del->data = del->next->data;
    del->next = del->next->next;

    // Your code here
}
struct Node *reverse(struct Node *head, int k)
{
    int temp = k;
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *nxt;
    while (curr && k != 0)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        k--;
    }
    if (nxt != NULL)
    {
        head->next = reverse(nxt, temp);
    }
    return prev;

    // Complete this method
}
void removeLoop(Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast && fast != NULL && fast->next != NULL);
    if (slow == fast)
    {
        fast = head;
        if (slow == fast)
        {
            while (slow->next != fast)
                slow = slow->next;
        }
        else
        {
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        slow->next = NULL;
    }
    // code here
    // just remove the loop without losing any nodes
}
bool isPalindrome(Node *head)
{
    stack<int> st;
    struct Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (st.top() != temp->data)
            return false;
        st.pop();
        temp = temp->next;
    }
    return true;
    //Your code here
}
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    struct Node *temp1 = reverseList(first);
    struct Node *temp2 = reverseList(second);
    int carry = 0;
    struct Node *newH = NULL;
    struct Node *temp;
    struct Node *temp3 = newH;
    while (temp1 && temp2)
    {
        int num = (temp1->data) + (temp2->data) + carry;
        if (num >= 10)
        {

            if (temp1->next == NULL && temp2->next == NULL)
            {
                // temp = new Node(num);
                while (num != 0)
                {
                    temp = new Node(num % 10);
                    temp3->next = temp;
                    temp3 = temp3->next;
                    num /= 10;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
                continue;
                // carry=1;
            }
            else
            {
                temp = new Node(num % 10);
                carry = 1;
            }
        }
        else
        {
            temp = new Node(num);
            carry = 0;
        }
        if (newH == NULL)
        {
            newH = temp;
            temp3 = newH;
        }
        else
        {
            temp3->next = temp;
            temp3 = temp3->next;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1)
    {
        int num = temp1->data + carry;
        if (num >= 10)
        {
            if (temp1->next != NULL)
            {
                temp1->data = num % 10;
                carry = 1;
            }
            else
            {
                // temp1->data = num;

                temp1->data = num % 10;
                temp3->next = temp1;
                temp3 = temp3->next;
                num /= 10;
                struct Node *t = new Node(num % 10);
                temp3->next = t;
                temp3 = temp3->next;
                temp1 = NULL;
                continue;
                // carry=0;
            }
        }
        else
        {
            temp1->data = num;
            carry = 0;
        }
        temp3->next = temp1;
        temp3 = temp3->next;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        int num = temp2->data + carry;
        if (num >= 10)
        {
            if (temp2->next != NULL)
            {
                temp2->data = num % 10;
                carry = 1;
            }
            else
            {
                // temp2->data = num;
                temp2->data = num % 10;
                temp3->next = temp2;
                temp3 = temp3->next;
                num /= 10;
                struct Node *t = new Node(num % 10);
                temp3->next = t;
                temp3 = temp3->next;
                temp2 = NULL;
                continue;
            }
        }
        else
        {
            temp2->data = num;
            carry = 0;
        }
        temp3->next = temp2;
        temp3 = temp3->next;
        temp2 = temp2->next;
    }
    newH = reverseList(newH);
    return newH;
    // code here
}
Node *findIntersection(Node *head1, Node *head2)
{
    Node *newH = NULL;
    Node *tail = NULL;
    Node *temp;
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *temp3 = head2;
    int l = 0;
    while (temp3)
    {
        l++;
        temp3 = temp3->next;
    }
    while (temp1 && l)
    {
        temp2 = head2;
        while (temp2)
        {
            if (temp1->data == temp2->data)
            {
                temp = new Node(temp1->data);
                if (newH == NULL)
                {
                    newH = temp;
                    tail = newH;
                }
                else
                {
                    tail->next = temp;
                    tail = tail->next;
                }
                l--;
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return newH;
    // Your Code Here
}
void Split(Node* head,Node** front,Node** back)
{
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}
Node* merge(Node* a,Node* b)
{
    Node* newH = NULL;

    if(a==NULL)
        return b;
    else if(b == NULL)
        return a;

    if(a->data <= b->data)
    {
        newH = a;
        newH->next = merge(a->next,b);
    }
    else
    {
        newH = b;
        newH->next = merge(a,b->next);
    }
    return newH;
}
Node *mergeSort(Node *head)
{
    Node* temp = head;
    Node* first;
    Node* second;

    if((temp==NULL)||(temp->next == NULL)){
        return temp;
    }
    Split(temp,&first,&second);

    first = mergeSort(first);
    second = mergeSort(second);

    return merge(first,second);

    // your code here
}
struct node* tail(struct node* head)
{
    while(head!=NULL&&head->next!=NULL)
        head=head->next;
    return head;
}
struct node* partition(struct node* head,struct node* end, struct node** newH,struct node** newB)
{
    struct node* pivot = end;
    struct node* prev = NULL;struct node* cur = head;struct node* tail = pivot;
    while(cur!=pivot)
    {
        if(cur->data < pivot->data)
        {
            if(*newH==NULL)
                *newH = cur;
            prev = cur;
            cur=cur->next;
        }
        else{
            if(prev)
                prev->next = cur->next;
            struct node* temp = cur->next;
            cur->next=NULL;
            tail->next=cur;
            tail=cur;
            cur=temp;
        }
    }
    if(*newH==NULL)
        *newH = pivot;

    *newB = tail;

    return pivot;
}
struct node* Recur(struct node* head,struct node* back)
{
    if(!head||head==back)
        return head;
    
    struct node* newH = NULL,*newB = NULL;

    struct node* pivot = partition(head,back,&newH,&newB);

    if(newH != pivot)
    {
        struct node* temp = newH;
        while(temp->next != pivot)
            temp=temp->next;
        temp->next = NULL;

        newH = Recur(newH,temp);

        temp = tail(newH);
        temp->next = pivot;
    }

    pivot->next = Recur(pivot->next,newB);

    return newH;
}
void quickSort(struct node **headRef) {
    (*headRef) = Recur((*headRef),tail(*headRef));
    return;
}
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head;
    Node* fast = head;
    Node* tail = slow;
    // Node* tmp = head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    while(tail->next!=head)
        tail=tail->next;
    // cout<<slow->data<<" "<<fast->data<<" "<<tail->data<<endl;
    tail->next=NULL;
    Node* temp = head;
    
    int l = 0;
    while(temp)
    {
        l++;
        temp=temp->next;
    }
    int size = l;
    temp = head;
    l/=2;
    Node* prev = temp;
    while(l&&temp)
    {
        prev = temp;
        temp=temp->next;
        l--;
    }
    if(size%2==0)
    {
        prev->next=NULL;
        *head1_ref=head;
        *head2_ref=temp;
    }
    else
    {
        *head2_ref=temp->next;
        temp->next=NULL;
        *head1_ref=head;
    }
    //Code to make the resultant linkedlist also circular
    // Node* t1 = *head1_ref;
    // Node* t2 = *head2_ref;
    // while(t1->next!=NULL)
    // {
    //     t1=t1->next;
    // }
    // t2->next=*head2_ref;
    // while(t2->next!=NULL)
    // {
    //     t2=t2->next;
    // }
    // t2->next=*head2_ref;
    // your code goes here
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
    cout<<"HELLO AND WELCOME LINKEDLIST PRACTISE SESSION"<<endl;
    int n;
    cin >> n;
    vector<int> v(n);
    fori(i, 0, n)
    {
        cin >> v[i];
    }
    struct Node *head = NULL;
    fori(i, 0, n)
    {
        create(head, v[i]);
    }
    printL(head);
    // cout << getCount(head) << endl;
    // struct Node *head1 = reverseList(head);
    // printL(head1);
    // int pos;
    // cin >> pos;
    // struct Node *temp = head;
    // // printL(head);
    // while (pos-- > 0)
    // {
    //     temp = temp->next;
    // }
    struct Node *flag = head;
    while (flag->next)
    {
        flag = flag->next;
    }
    flag->next = head;
    string r = (detectLoop(head)) ? "Yess" : "No";
    cout << r << endl;
    Node* head1 = NULL;
    Node* head2 = NULL;
    splitList(head,&head1,&head2);
    printL(head1);
    printL(head2);
    // removeLoop(head);
    // printL(head);
    // string result = (detectLoop(head)) ? "Yess" : "No";
    // cout << result << endl;
    // cout<<getMiddle(head)<<endl;
    // int k;
    // cin>>k;
    // cout<<getNthFromLast(head,k);
    // deleteNode(head->next);
    // printL(head);
    // printL(reverse(head,k));
    // cout<<isPalindrome(head)<<endl;
    // int m;
    // cin>>m;
    // vector<int> A(m);
    // fori(i, 0, m)
    // {
    //     cin >> A[i];
    // }
    // struct Node *head2 = NULL;
    // fori(i, 0, m)
    // {
    //     create(head2, A[i]);
    // }
    // printL(head);
    // printL(head2);
    // quickSort(&head);
    // printL(head);
    return 0;
}