//https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//Best Approach
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    /*
    ListNode* start = new ListNode();
    start->next = head;
    ListNode* fast = start;
    ListNode* slow = start;

    for(int i=1;i<=n;i++)
        fast = fast -> next;
    
    while(fast -> next!=NULL)
    {
        fast = fast -> next;
        slow = slow->next;
    }
    slow -> next = slow->next->next;
    return start->next;*/
    
    
    /*
    Naive Approach
    int l = 0;
    ListNode* temp = head;
    while(temp)
    {
        l++;
        temp = temp->next;
    }
    int tofind = l-n;
    int cnt = 0;
    temp = head;
    ListNode* p = temp;
    if(head==NULL) return head;
    else if(n==l)
    {
        ListNode* op = head;
        
        
        head = head->next;
        delete op;
        return head;
    }
    while(temp)
    {
        if(cnt==tofind)
        {
            p->next = temp->next;
            delete temp;
            break;
        }
        
        p=temp;
        temp = temp->next;
        cnt++;
    }
    return head;*/
}
};