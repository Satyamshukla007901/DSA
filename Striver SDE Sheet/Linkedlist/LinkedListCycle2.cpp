//https://leetcode.com/problems/linked-list-cycle-ii/submissions/
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        
        if(slow == NULL or fast == NULL or fast->next==NULL) return NULL;
        
        fast = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;