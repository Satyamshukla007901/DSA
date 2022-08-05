//https://leetcode.com/problems/intersection-of-two-linked-lists/
        ListNode* ok1 = headA;
        ListNode* ok2 = headB;
        int l1 = length(ok1);
        int l2 = length(ok2);
        if(l2>l1)
        {
            ok1 = headB;
            ok2 = headA;
        }
        int d = abs(l1-l2);
        while(d-->0)
        {
            ok1 = ok1->next;
        }
        
        while(ok1 and ok2 and ok1!=ok2)
        {
            ok1=ok1->next;
            ok2=ok2->next;
        }
        return ok1;