//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> ans;
    if(root==NULL)
            return ans;
    queue<TreeNode*> q;
    q.push(root);bool f = false;
    while(!q.empty())
    {
        int sz = q.size();
        vector<int> ok;
        for(int i=1;i<=sz;i++)
        {
            TreeNode* t = q.front();
            q.pop();
            ok.push_back(t->val);
            if(t->left)
                    q.push(t->left);
            if(t->right)
                    q.push(t->right);
        }
        if(f==false)
        {
            f=true;
        }
        else
        {
            f=false;
            reverse(ok.begin(),ok.end());
        }
        ans.push_back(ok);
    }
    return ans;
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vp;
        if(root==NULL)
                return vp;
        vp = levelOrder(root);
        
        return vp;
    }