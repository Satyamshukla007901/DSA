//https://leetcode.com/problems/merge-two-sorted-lists/submissions/
    if(l1==NULL) return l2;
    else if(l2==NULL) return l1;
    ListNode* ok = new ListNode(0);
    if(l1->val<l2->val)
    {
        ok->next = l1;
        l1 = l1->next;
    }
    else
    {
        ok->next = l2;
        l2 = l2->next;
    }
    ListNode* temp = ok->next;
    while(l1 and l2)
    {
        if(l1->val<l2->val)
        {
            temp->next = l1;
            temp = temp->next;
            l1=l1->next;
        }
        else
        {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
    }
    if(l1) temp->next = l1;
    else temp->next = l2;
    return ok->next;