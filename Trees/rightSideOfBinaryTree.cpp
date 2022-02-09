//https://leetcode.com/problems/binary-tree-right-side-view/submissions/
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> vp;
    if (root == NULL)
        return vp;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> t;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *temp = q.front();
            // cout<<temp->val<<" ";
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            t.push_back(temp->val);
        }
        // cout << endl;
        vp.push_back(t);
    }
    return vp;
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vp;
        if(root==NULL)
                return vp;
        vector<vector<int>> ok = levelOrder(root);
        for(auto &value:ok)
        {
            vp.push_back(value[value.size()-1]);
        }
        return vp;
    }

//recursive my approach
    void solve(TreeNode* root,vector<int> &vp,map<int,int> &mp,int cnt)
    {
        if(root==NULL)
                return;
        mp[cnt]=root->val;
        solve(root->left,vp,mp,cnt+1);
        solve(root->right,vp,mp,cnt+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        vector<int> vp;
        if(root==NULL)
                return vp;
        solve(root,vp,mp,0);
        for(auto &value:mp)
                vp.push_back(value.second);
        return vp;
    }