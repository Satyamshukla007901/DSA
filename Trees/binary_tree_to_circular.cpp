//https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1#
    void inOrder(Node* root,vector<Node*> &vp)
    {
        if(root==NULL)
            return;
        inOrder(root->left,vp);
        vp.push_back(root);
        inOrder(root->right,vp);
    }
    Node *bTreeToCList(Node *root)
    {
        if(root==NULL)
            return NULL;
        vector<Node*> vp;
        inOrder(root,vp);
        for(int i=0;i<vp.size();i++)
        {
            if(i==0)
            {
                vp[i]->right = vp[i+1];
            }
            else if(i==vp.size()-1)
            {
                vp[i]->left=vp[i-1];
            }
            else
            {
                vp[i]->left=vp[i-1];
                vp[i]->right=vp[i+1];
            }
        }
        vp[0]->left=vp[vp.size()-1];
        vp[vp.size()-1]->right=vp[0];
        return vp[0];
    //add code here.
    }

//https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1#
    void inOrder(Node* root,vector<int> &vp)
    {
        if(root==NULL)
            return;
        inOrder(root->left,vp);
        vp.push_back(root->data);
        inOrder(root->right,vp);
    }
    int isPairPresent(struct Node *root, int target)
    {
        vector<int> vp;
        inOrder(root,vp);
        unordered_map<int,int> mp;
        for(auto &value:vp)
        {
            mp[value]=1;
        }
        for(auto &value:vp)
        {
            if(mp.find(target-value)!=mp.end())
                return true;
        }
        return false;
    //add code here.
    }

//another approach
    void inOrder(Node* root,unordered_map<int,int> &mp)
    {
        if(root==NULL)
            return;
        inOrder(root->left,mp);
        mp[root->data]=1;
        inOrder(root->right,mp);
    }
    bool solve(Node* root,unordered_map<int,int> &mp,int k)
    {
        if(root==NULL)
            return false;
        if(mp.find(k-root->data)!=mp.end())
            return true;
        return solve(root->left,mp,k)||solve(root->right,mp,k);
    }
    int isPairPresent(struct Node *root, int target)
    {
        if(root==NULL)
            return false;
        unordered_map<int,int> mp;
        inOrder(root,mp);
        if(mp.find(target-root->data)!=mp.end())
            return true;
        return solve(root,mp,target);
        
    //add code here.
    }