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