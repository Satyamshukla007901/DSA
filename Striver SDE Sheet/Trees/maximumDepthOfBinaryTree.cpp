//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
TC->O(N)
SC->O(N)
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
    int maxDepth(TreeNode* root){
        // int  count = 0;
        if(root==NULL)
                return 0;
    
        return 1 + max(maxDepth(root->left) , maxDepth(root->right));
        
    }
};