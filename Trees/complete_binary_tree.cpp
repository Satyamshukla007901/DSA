//https://practice.geeksforgeeks.org/problems/complete-binary-tree/1
    bool isCompleteBT(Node* root){
        if(root==NULL)
            return true;
        
        queue<Node*> q;bool rcheck = true;bool lcheck = true;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left)
            {
                if(lcheck == false)
                    return false;
                q.push(temp->left);
            }
            else
            {
                rcheck = false;
            }
            
            if(temp->right)
            {
                if(rcheck==false)
                {
                    return false;
                }
                q.push(temp->right);
            }
            else
            {
                lcheck = false;
            }
            
        }
        
        return true;
        
        //code heres
    }

//https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#
    void inOrder(Node* root,vector<Node*> &vp)
    {
        if(root==NULL)
            return;
        inOrder(root->left,vp);
        vp.push_back(root);
        inOrder(root->right,vp);
    }
    void populateNext(Node *root)
    {
        if(root==NULL)
            return;
        vector<Node*> vp;
        inOrder(root,vp);
        for(int i=0;i<vp.size();i++)
        {
            if(i==vp.size()-1)
            {
                vp[i]->next=NULL;
            }
            else
                vp[i]->next=vp[i+1];
                
        }
        //code here
    }