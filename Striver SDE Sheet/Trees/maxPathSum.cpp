// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// TC - > O(N)
//  SC->O(N)
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
    int solve(TreeNode* root,int &maxi)
    {
        if(root==NULL)
                return 0;
        int lsum = max(0,solve(root->left,maxi));
        int rsum = max(0,solve(root->right,maxi));
        maxi = max(maxi,root->val+lsum+rsum);
        
        return root->val+max(lsum,rsum);  
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};