//https://leetcode.com/problems/symmetric-tree/
// TC->O(N)
// SC->O(N)
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
    bool same(TreeNode *p,TreeNode *q)
    {
        if(p==NULL&&q==NULL)
                return true;
        
        if(p!=NULL and q==NULL) return false;
        else if(p==NULL and q!=NULL) return false;
        
        
        return (p->val==q->val)&&same(p->left,q->right)&&same(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
                return true;
        
        return same(root->left,root->right);
    }
};