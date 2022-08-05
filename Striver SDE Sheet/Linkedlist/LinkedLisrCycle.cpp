//https://leetcode.com/problems/linked-list-cycle/
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        
        if(slow == NULL or fast == NULL or fast->next==NULL) return false;
        return true;