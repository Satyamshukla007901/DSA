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

    node(int x)
    {
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
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x)
    {
        val = x;
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
//Reverse K Group in wich left out elements should be left as it is
ListNode *reverseKGroup(ListNode *head, int k)
{

    ListNode *temp = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;
    int count = k;
    int l = 0;
    ListNode *t = head;
    while (t)
    {
        l++;
        t = t->next;
    }
    if (l < k)
        return head;
    while (temp && count)
    {

        next = temp->next;
        temp->next = prev;
        prev = temp;
        count--;
        temp = next;
    }
    if (next != NULL)
    {
        head->next = reverseKGroup(next, k);
    }
    return prev;
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
void Split(Node *head, Node **front, Node **back)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}
Node *merge(Node *a, Node *b)
{
    Node *newH = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (a->data <= b->data)
    {
        newH = a;
        newH->next = merge(a->next, b);
    }
    else
    {
        newH = b;
        newH->next = merge(a, b->next);
    }
    return newH;
}
Node *mergeSort(Node *head)
{
    Node *temp = head;
    Node *first;
    Node *second;

    if ((temp == NULL) || (temp->next == NULL))
    {
        return temp;
    }
    Split(temp, &first, &second);

    first = mergeSort(first);
    second = mergeSort(second);

    return merge(first, second);

    // your code here
}
struct node *tail(struct node *head)
{
    while (head != NULL && head->next != NULL)
        head = head->next;
    return head;
}
struct node *partition(struct node *head, struct node *end, struct node **newH, struct node **newB)
{
    struct node *pivot = end;
    struct node *prev = NULL;
    struct node *cur = head;
    struct node *tail = pivot;
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if (*newH == NULL)
                *newH = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            struct node *temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    if (*newH == NULL)
        *newH = pivot;

    *newB = tail;

    return pivot;
}
struct node *Recur(struct node *head, struct node *back)
{
    if (!head || head == back)
        return head;

    struct node *newH = NULL, *newB = NULL;

    struct node *pivot = partition(head, back, &newH, &newB);

    if (newH != pivot)
    {
        struct node *temp = newH;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        newH = Recur(newH, temp);

        temp = tail(newH);
        temp->next = pivot;
    }

    pivot->next = Recur(pivot->next, newB);

    return newH;
}
void quickSort(struct node **headRef)
{
    (*headRef) = Recur((*headRef), tail(*headRef));
    return;
}
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow = head;
    Node *fast = head;
    Node *tail = slow;
    // Node* tmp = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    while (tail->next != head)
        tail = tail->next;
    // cout<<slow->data<<" "<<fast->data<<" "<<tail->data<<endl;
    tail->next = NULL;
    Node *temp = head;

    int l = 0;
    while (temp)
    {
        l++;
        temp = temp->next;
    }
    int size = l;
    temp = head;
    l /= 2;
    Node *prev = temp;
    while (l && temp)
    {
        prev = temp;
        temp = temp->next;
        l--;
    }
    if (size % 2 == 0)
    {
        prev->next = NULL;
        *head1_ref = head;
        *head2_ref = temp;
    }
    else
    {
        *head2_ref = temp->next;
        temp->next = NULL;
        *head1_ref = head;
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
//Delete Alternate Elements
void deleteAlt(struct Node *head)
{

    Node *temp = head;
    Node *t;
    while (temp->next && temp->next->next)
    {
        t = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        delete t;
    }
    delete temp->next;
    temp->next = NULL;
    // Code here
}
//Removed Duplicates from Linked list which is unserted
Node *removeDuplicates(Node *head)
{
    int arr[10001] = {0};
    Node *temp = head->next;
    Node *prev = head;
    arr[head->data]++;
    while (temp)
    {
        arr[temp->data]++;
        if (arr[temp->data] > 1)
        {
            Node *t = temp;
            prev->next = temp->next;
            delete t;
        }
        else
        {
            prev = temp;
        }
        temp = prev;
        temp = temp->next;
    }
    return head;

    // your code goes here
}
//Removed Duplicates from Linked list which is unserted
//1->2->2->2->4
//1->2->4
void removeDuplicates2(struct Node *head)
{
    Node *temp = head->next;
    Node *prev = head;
    while (temp)
    {
        if (prev->data == temp->data)
        {
            Node *t = temp;
            prev->next = temp->next;
            delete t;
        }
        else
            prev = temp;
        temp = prev->next;
    }
}
//Function to insert a node in the middle of the linked list.
Node *insertInMiddle(Node *head, int x)
{
    Node *temp = head;
    int l = getCount(head);

    int count = 0;
    // Node* prev=head;
    if ((int)(l / 2.0) != (l / 2.0))
    {
        while (temp)
        {
            if ((int)(l / 2.0) != (l / 2.0) && l / 2 == count)
            {
                Node *node = new Node(x);
                node->next = temp->next;
                temp->next = node;
            }

            count++;
            // prev=temp;
            temp = temp->next;
        }
    }
    else
    {
        while (temp)
        {

            if ((l / 2 - 1) == count)
            {
                Node *node = new Node(x);
                node->next = temp->next;
                temp->next = node;
            }
            count++;
            // prev=temp;
            temp = temp->next;
        }
    }
    return head;
    // Code here
}
//Modular Node from last
int modularNode(Node *head, int k)
{
    int ans = -1;
    Node *temp = head;
    int idx = 1;
    while (temp)
    {
        if (idx % k == 0)
            ans = temp->data;
        temp = temp->next;
        idx++;
    }
    return ans;
    // Code here
}
//Count Pairs whose sum is equal to X
int countPairs(struct Node *head1, struct Node *head2, int x)
{
    unordered_map<int, int> ump;
    Node *temp = head1;
    while (temp)
    {
        ump[x - temp->data]++;
        temp = temp->next;
    }
    temp = head2;
    int count = 0;
    while (temp)
    {
        ump[temp->data]++;
        count += (ump[temp->data] > 1);
        temp = temp->next;
    }
    return count;
    // Code here
}
//Delete nodes having greater value on right
Node *compute_Correct(Node *head)
{
    Node *newHead = reverseList(head);

    Node *temp = newHead;
    int maxm = temp->data;
    while (temp && temp->next)
    {
        if (temp->next->data < maxm)
        {
            Node *t = temp->next;
            temp->next = temp->next->next;
            delete t;
        }
        else
        {
            temp = temp->next;
            maxm = temp->data;
        }
    }
    return reverseList(newHead);
    // your code goes here
}
//Approach of me
Node *compute2(Node *head)
{
    Node *temp = head;
    while (head && head->next && head->data < head->next->data)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }
    temp = head;
    while (temp && temp->next)
    {
        if (temp && temp->next && temp->data < temp->next->data)
        {

            temp->data = temp->next->data;
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            temp = head;
        }
        else
            temp = temp->next;
    }
    return head;
    // your code goes here
}
//Approach TLE and Wrong
Node *compute(Node *head)
{
    Node *temp = head;
    while (head && head->next && head->data < head->next->data)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }
    temp = head;
    while (temp && temp->next)
    {
        if (temp && temp->next && temp->data < temp->next->data)
        {

            temp->data = temp->next->data;
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else
            temp = temp->next;
    }
    return head;
    // your code goes here
}
//Nth lode from last
/*
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int l = 0;
    while (temp)
    {
        temp = temp->next;
        l++;
    }
    int toFind = l - n;
    int count = 0;
    temp = head;
    ListNode *prev = head;
    while (temp)
    {
        if (count == toFind)
        {
            if (temp->next)
            {
                temp->val = temp->next->val;
                ListNode *t = temp->next;
                temp->next = temp->next->next;
                delete t;
            }
            else
            {
                if (head->next)
                {
                    prev->next = NULL;
                    delete temp;
                    return head;
                }
                else
                {
                    delete temp;
                    return NULL;
                }
            }
        }
        count++;
        prev = temp;
        temp = temp->next;
    }
    return head;
}
//Best Approach
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *start = new ListNode();
    start->next = head;
    ListNode *fast = start;
    ListNode *slow = start;

    for (int i = 1; i <= n; i++)
        fast = fast->next;

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
}
*/
/*
//Middle Element best Approach
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//Merge Two Sorted Linkedlist
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1 && !l2)
        return NULL;
    ListNode *temp1 = l1, *temp2 = l2;
    ListNode *head = l2;
    ListNode *temp = head, *prev = head;
    while (temp1)
    {
        temp2 = head;
        prev = temp2;
        ListNode *node = new ListNode(temp1->val);
        while (temp2 && temp1->val > temp2->val)
        {
            prev = temp2;
            temp2 = temp2->next;
        }
        node->next = temp2;

        if (temp2 == head)
        {
            head = node;
        }
        else
            prev->next = node;

        temp1 = temp1->next;
    }

    return head;
}
*/
//Method Using a Set
/*
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    multiset<int> s;
    ListNode *temp = l1;
    while (temp)
    {
        s.insert(temp->val);
        temp = temp->next;
    }
    temp = l2;
    while (temp)
    {
        s.insert(temp->val);
        temp = temp->next;
    }
    ListNode *head = NULL;
    temp = head;
    for (auto &value : s)
    {
        ListNode *node = new ListNode(value);
        if (!head)
        {
            head = node;
            temp = head;
        }
        else
        {
            temp->next = node;
            temp = temp->next;
        }
    }
    return head;
}*/
//Add Two Numbers
/*
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *temp = l1;
    ListNode *temp1 = l2;
    ListNode *head = NULL;
    ListNode *tmp = head;
    while (temp && temp1)
    {
        ListNode *node;
        int sum = temp->val + temp1->val + carry;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        node = new ListNode(sum);
        if (!head)
        {
            head = node;
            tmp = head;
        }
        else
        {
            tmp->next = node;
            tmp = tmp->next;
        }
        temp = temp->next;
        temp1 = temp1->next;
    }
    while (temp)
    {
        int sum = temp->val + carry;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
            carry = 0;
        ListNode *node = new ListNode(sum);
        if (!head)
        {
            head = node;
            tmp = head;
        }
        else
        {
            tmp->next = node;
            tmp = tmp->next;
        }
        temp = temp->next;
    }
    while (temp1)
    {
        int sum = temp1->val + carry;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
            carry = 0;
        ListNode *node = new ListNode(sum);
        if (!head)
        {
            head = node;
            tmp = head;
        }
        else
        {
            tmp->next = node;
            tmp = tmp->next;
        }
        temp1 = temp1->next;
    }
    if (carry != 0)
    {
        ListNode *node = new ListNode(carry);
        if (!head)
        {
            head = node;
            tmp = head;
        }
        else
        {
            tmp->next = node;
            tmp = tmp->next;
        }
    }
    return head;
}*/
/*
//Absolute list sorting
void sortList(Node **head)
{
    Node *temp = *head;
    Node *prev = temp;
    while (temp)
    {
        if (temp->data < 0 && prev != temp)
        {
            prev->next = temp->next;
            temp->next = *head;
            *head = temp;
            temp = prev;
        }

        prev = temp;
        temp = temp->next;
    }
    // Your Code Here
}
//merge two sorted list in reverse order
//Space Complexirty O(N)
struct Node *mergeResult(Node *node1, Node *node2)
{
    multiset<int, greater<int>> s;
    while (node1)
    {
        s.insert(node1->data);
        node1 = node1->next;
    }
    while (node2)
    {
        s.insert(node2->data);
        node2 = node2->next;
    }
    Node *head = NULL;
    Node *temp = head;
    for (auto &value : s)
    {
        Node *node = new Node();
        node->data = value;
        if (head == NULL)
        {
            head = node;
            temp = head;
        }
        else
        {
            temp->next = node;
            temp = temp->next;
        }
    }
    return head;

    // your code goes here
}
//Btter Approach Space O(1)
// Given two non-empty linked lists 'a' and 'b'
Node *SortedMerge(Node *a, Node *b)
{
    // If both lists are empty
    if (a == NULL && b == NULL)
        return NULL;

    // Initialize head of resultant list
    Node *res = NULL;

    // Traverse both lists while both of then
    // have nodes.
    while (a != NULL && b != NULL)
    {
        // If a's current value is smaller or equal to
        // b's current value.
        if (a->key <= b->key)
        {
            // Store next of current Node in first list
            Node *temp = a->next;

            // Add 'a' at the front of resultant list
            a->next = res;
            res = a;

            // Move ahead in first list
            a = temp;
        }

        // If a's value is greater. Below steps are similar
        // to above (Only 'a' is replaced with 'b')
        else
        {
            Node *temp = b->next;
            b->next = res;
            res = b;
            b = temp;
        }
    }

    // If second list reached end, but first list has
    // nodes. Add remaining nodes of first list at the
    // front of result list
    while (a != NULL)
    {
        Node *temp = a->next;
        a->next = res;
        res = a;
        a = temp;
    }

    // If first list reached end, but second list has
    // node. Add remaining nodes of first list at the
    // front of result list
    while (b != NULL)
    {
        Node *temp = b->next;
        b->next = res;
        res = b;
        b = temp;
    }

    return res;
}
//Arrange Consonants and Vowels
struct Node *arrange(Node *head)
{
    Node *phead = head;
    Node *temp, *p;
    if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u')
    {

        while (head && head->next && (head->next->data == 'a' || head->next->data == 'e' || head->next->data == 'i' || head->next->data == 'o' || head->next->data == 'u'))
        {
            head = head->next;
        }
    }
    if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u')
    {
        temp = head->next;
        p = head->next;
    }
    else
    {
        temp = head;
        p = head;
    }

    while (temp)
    {
        if (temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u')
        {
            // while(head->next->data=='a'||head->next->data=='e'||head->next->data=='i'||head->next->data=='o'||head->next->data=='u')
            // {
            //     head=head->next;
            // }
            p->next = temp->next;
            if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u')
            {
                temp->next = head->next;
                head->next = temp;
                head = head->next;
            }
            else
            {
                temp->next = head;
                head = temp;
                phead = temp;
            }

            temp = p->next;
        }
        else
        {
            p = temp;
            temp = temp->next;
        }
    }

    return phead;
    //Code here
}*/
//Flatten Linked List
/*
Node *meerge(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a != NULL)
        temp->bottom = a;
    else
        temp->bottom = b;
    return res->bottom;
}
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);
    root = meerge(root, root->next);
    return root;
    // Your code here
}
//Rotate a Linekdlist
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
    ListNode *temp = head;
    int l = 0;
    while (temp)
    {
        l++;
        temp = temp->next;
    }
    if (k == 0 || l == k || l == 1 || k % l == 0)
        return head;
    int x = k % l;
    temp = head;
    ListNode *prev = head;
    x = l - x;
    while (x-- > 0)
    {
        prev = temp;
        if (!temp)
            temp = head;
        temp = temp->next;
    }
    ListNode *newHead = temp;
    if (prev)
        prev->next = NULL;
    while (temp && temp->next)
    {
        temp = temp->next;
    }
    if (temp)
        temp->next = head;
    head = newHead;
    return head;
}*/
// struct Node *reverseList(struct Node *head)
// {
//     struct Node *prev = NULL;
//     struct Node *curr = head;
//     while (curr)
//     {
//         struct Node *nxt = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = nxt;
//     }
//     return prev;
//     // code here
//     // return head of reversed list
// }
Node *inPlace(Node *root)
{
    Node *temp = root;
    vector<int> vp;
    while (temp)
    {
        vp.push_back(temp->data);
        temp = temp->next;
    }
    vector<int> a;
    for (int i = 0; i <= vp.size() / 2 - 1; i++)
    {
        a.push_back(vp[i]);

        a.push_back(vp[vp.size() - i - 1]);
    }
    if (vp.size() % 2 == 1)
        a.push_back(vp[vp.size() / 2]);

    cout << endl;
    Node *head = NULL;
    Node *t = head;
    for (auto &value : a)
    {
        Node *node = new Node(value);
        if (head == NULL)
        {
            head = node;
            t = head;
        }
        else
        {
            t->next = node;
            t = t->next;
        }
    }
    return head;
    // your code goes here
}
//My Better Approach
Node *inPlace(Node *root)
{
    Node *temp = root;
    while (temp && temp->next)
    {
        Node *t = temp->next;
        Node *prev = temp;
        while (t && t->next)
        {
            prev = t;
            t = t->next;
        }
        prev->next = NULL;
        Node *help = temp->next;
        temp->next = t;
        temp->next->next = help;
        temp = temp->next->next;
    }
    return root;
    // your code goes here
}
//INplace More Effiecient My Approach
void reorderList(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *head1 = head;
    Node *head2 = reverseList(slow->next);
    slow->next = NULL;
    while (head2)
    {

        Node *a = head2->next;
        Node *b = head1->next;
        head2->next = b;
        head1->next = head2;
        head1 = b;
        head2 = a;
    }
    return;
    // Your code here
}
//Adding two Polynomial
Node *addPolynomial(Node *p1, Node *p2)
{
    Node *dummy = new Node(0, 0);
    Node *temp;
    if (p1->pow > p2->pow)
    {
        dummy->next = p1;

        p1 = p1->next;
    }
    else if (p1->pow < p2->pow)
    {
        dummy->next = p2;
        p2 = p2->next;
    }
    else
    {
        p1->coeff += p2->coeff;
        dummy->next = p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    temp = dummy->next;
    while (p1 && p2)
    {
        Node *a = p1->next;
        Node *b = p2->next;
        if (p1->pow > p2->pow)
        {
            temp->next = p1;
            p1 = a;
        }
        else if (p1->pow < p2->pow)
        {
            temp->next = p2;
            p2 = b;
        }
        else
        {
            p1->coeff += p2->coeff;
            temp->next = p1;
            p1 = a;
            p2 = b;
        }
        temp = temp->next;
    }
    while (p1)
    {
        temp->next = p1;
        temp = temp->next;
        p1 = p1->next;
    }
    while (p2)
    {
        temp->next = p2;
        temp = temp->next;
        p2 = p2->next;
    }
    if (temp)
        temp->next = NULL;
    return dummy->next;
    //Your code here
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    fori(i, 0, n)
    {
        cin >> v[i];
    }
    Node *head = NULL;
    fori(i, 0, n)
    {
        create(head, v[i]);
    }
    // printL(head);
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
    // struct Node *flag = head;
    // while (flag->next)
    // {
    //     flag = flag->next;
    // }
    // flag->next = head;
    // string r = (detectLoop(head)) ? "Yess" : "No";
    // cout << r << endl;
    // Node *head1 = NULL;
    // Node *head2 = NULL;
    // splitList(head, &head1, &head2);
    // printL(head1);
    // printL(head2);
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
    int m;
    cin >> m;
    vector<int> A(m);
    fori(i, 0, m)
    {
        cin >> A[i];
    }
    Node *head2 = NULL;
    fori(i, 0, m)
    {
        create(head2, A[i]);
    }
    printL(head);
    printL(head2);
    // quickSort(&head);
    // printL(head);
    // int key;
    // cin >> key;
    // cout << "----------------------------------" << endl;
    // Node *newHead = compute(head);
    // // // removeDuplicates2(head);

    // printL(newHead);
    // cout << modularNode(head, key) << endl;
    printL(reverseList(head));
    printL(reverseList(head2));
    printL(inPlace(head));
    printL(inPlace(head2));
    return 0;
}