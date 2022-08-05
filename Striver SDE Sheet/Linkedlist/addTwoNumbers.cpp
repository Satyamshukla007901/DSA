//https://leetcode.com/problems/add-two-numbers/submissions/
        int carry = 0;
        ListNode* ok1 = l1;
        ListNode* ok2 = l2;
        ListNode* newHead = NULL;
        ListNode* tail = NULL;
        
        while(ok1 and ok2)
        {
            int sum = ok1->val+ok2->val+carry;
            carry = sum/10;
            sum = sum%10;
            if(newHead==NULL)
            {
                newHead = new ListNode(sum);
                tail = newHead;
            }
            else
            {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            ok1 = ok1->next;
            ok2 = ok2->next;
        }
        while(ok1)
        {
            int sum = ok1->val+carry;
            carry = sum/10;
            sum=sum%10;
            if(newHead==NULL)
            {
                newHead = new ListNode(sum);
                tail = newHead;
            }
            else
            {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            ok1 = ok1->next;
        }
        while(ok2)
        {
            int sum = ok2->val+carry;
            carry = sum/10;
            sum=sum%10;
            if(newHead==NULL)
            {
                newHead = new ListNode(sum);
                tail = newHead;
            }
            else
            {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            ok2 = ok2->next;
        }
        if(carry)
        {
            if(newHead==NULL)
            {
                newHead = new ListNode(carry);
                tail = newHead;
            }
            else
            {
                tail->next = new ListNode(carry);
                tail = tail->next;
            }
        }
        return newHead;