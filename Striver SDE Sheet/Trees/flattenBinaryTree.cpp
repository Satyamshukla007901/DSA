//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//TC->O(N)
//SC->O(1)
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
    /*
    void preorder(TreeNode* root,vector<TreeNode*> &vp)
    {
        if(root==NULL)
                return;
        vp.push_back(root);
        preorder(root->left,vp);
        preorder(root->right,vp);
        
    }*/
    void flatten(TreeNode* root) {
        if(root==NULL)
                return;
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* prev = curr->left;
                while(prev->right)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr=curr->right;
        }
    }
};