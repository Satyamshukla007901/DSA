// https://leetcode.com/problems/middle-of-the-linked-list/
        /*
        int cnt = 0;
        int l = length(head);
        ListNode* temp = head;
        while(temp)
        {
            if(cnt==l/2)
            {
                return temp;
            }
            temp=temp->next;
            cnt++;
        }
        return head;*/
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;