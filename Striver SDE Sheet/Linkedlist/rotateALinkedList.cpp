//https://leetcode.com/problems/rotate-list/
        if(head==NULL)
            return NULL;
        if(head->next==NULL) return head;
        int l = 0;
        ListNode* temp = head;
        while(temp)
        {
            l++;
            temp=temp->next;
        }
        if(k==0 or k%l==0) return head;
        k%=l;
        temp = head;
        int x = l-k;
        while(x-->1)
        {
            temp = temp->next;
        }
        ListNode* t = temp->next;
        temp->next = NULL;
        ListNode* tail = t;
        while(tail and tail->next)
        {
            tail=tail->next;
        }
        tail->next = head;
        head = t;
        return head;
