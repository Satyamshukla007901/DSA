//https://leetcode.com/problems/copy-list-with-random-pointer/submissions/
        Node* Head = new Node(head->val);
        Node* tail = Head;
        map<Node*,Node*> mp;
        Node* temp = head->next;
        mp[head] = Head;
        
        while(temp)
        {
            Node* node = new Node(temp->val);
            tail->next = node;
            tail = tail->next;
            mp[temp] = tail;
            temp=temp->next;
        }
        
        temp = head;
        tail = Head;
        
        while(temp)
        {
            if(temp->random)
                tail->random = mp[temp->random];
            else tail->random = NULL;
            tail=tail->next;
            temp=temp->next;
        }
        return Head;
    }