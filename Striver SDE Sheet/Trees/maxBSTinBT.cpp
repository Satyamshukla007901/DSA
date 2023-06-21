//https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// TC->O(N)
//  SC->O(1)
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
int ans = 0;
    vector<int> f(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,INT_MIN,INT_MAX,0};
        }
       
        auto l = f(root->left);
        auto r = f(root->right);

        if(root->val>l[1] and root->val<r[2])
        {
            ans = max(ans,l[3]+r[3]+root->val);
            return {l[0]+r[0]+1,max(root->val,r[1]),min(root->val,l[2]),(l[3]+r[3]+root->val)};
        }
        ans=max(ans,max(l[3],r[3]));
        return {max(l[0],r[0]),INT_MAX,INT_MIN,max(l[3],r[3])};
    }
    int maxSumBST(TreeNode* root) {
        vector<int> ok = f(root);
        return max(ans,0);
    }
};