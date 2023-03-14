//https://leetcode.com/problems/same-tree/
//TC - O(N)
//SC - O(N)

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL&&q!=NULL)
                return false;
        if(p!=NULL&&q==NULL)
                return false;
        bool c = p->val==q->val;
        bool l = isSameTree(p->left,q->left);
        bool r = isSameTree(p->right,q->right);
        return l&&r&&c;
        
        
        
        }
};