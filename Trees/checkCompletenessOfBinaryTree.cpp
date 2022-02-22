//https://leetcode.com/problems/check-completeness-of-a-binary-tree/submissions/
    vector<TreeNode*> levelOrder(TreeNode* root)
    {
    vector<TreeNode*> vp;
    if (root == NULL)
        return vp;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *temp = q.front();
            // cout<<temp->val<<" ";
            q.pop();
            if (temp)
            {
                q.push(temp->left);
            }
            if (temp)
            {
                q.push(temp->right);
            }
            vp.push_back(temp);
        }
        // cout << endl;
        
    }
    return vp;
    }
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)return true;
        vector<TreeNode*> ok = levelOrder(root);
        for(auto &value:ok)
        {
            if(value)
                cout<<value->val<<" ";
            else
                cout<<"null"<<" ";
        }
        cout<<endl;
        int l = ok.size();
        int e = l-1;
        for(int i=l-1;i>=0;i--)
        {
            if(ok[i]!=NULL)
            {
                e=i;
                break;
            }
        }
        for(int i=0;i<=e;i++)
        {
            if(ok[i]==NULL)
                    return false;
        }
        return true;
    }