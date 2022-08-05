//https://leetcode.com/problems/palindrome-linked-list/
        if(head==NULL or head->next==NULL) return true;
        ListNode* nHead = NULL;
        nHead = new ListNode(head->val);
        ListNode* tail = nHead;
        ListNode* temp = head->next;
        while(temp)
        {
            tail->next = new ListNode(temp->val);
            tail = tail->next;
            temp=temp->next;
        }
        tail->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        while(head)
        {
            if(head->val!=nHead->val) return false;
            head = head->next;
            nHead = nHead->next;
        }
        return true;