//https://leetcode.com/problems/reverse-nodes-in-k-group/
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int count=k;
        int l=0;
        ListNode* t = head;
        while(t)
        {
            l++;
            t=t->next;
        }
        if(l<k)
            return head;
        while(temp&&count)
        {
            
            next=temp->next;
            temp->next=prev;
            prev=temp;
            count--;
            temp=next;
        }
        
        head->next = reverseKGroup(next,k);
        
        return prev;
        
    }