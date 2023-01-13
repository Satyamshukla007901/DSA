https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,map<int,map<int,multiset<int>>> &mp,int cnt,int l)
    {
        if(root==NULL)
                return;
        
        mp[cnt][l].insert(root->val);
        solve(root->left,mp,cnt-1,l+1);
        solve(root->right,mp,cnt+1,l+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        solve(root,mp,0,0);
        vector<vector<int>> ans;
        for(auto &value:mp)
        {
            vector<int> ok;
            for(auto &val:value.second)
            {
                // sort(val.second.begin(),val.second.end());
                for(auto &v:val.second)
                        ok.push_back(v);
            }
            ans.push_back(ok);
        }
        return ans;
    }
};