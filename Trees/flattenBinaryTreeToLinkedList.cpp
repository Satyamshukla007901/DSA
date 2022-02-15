//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/
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
    void preorder(TreeNode* root,vector<TreeNode*> &vp)
    {
        if(root==NULL)
                return;
        vp.push_back(root);
        preorder(root->left,vp);
        preorder(root->right,vp);
        
    }
    void flatten(TreeNode* root) {
        if(root==NULL)
                return;
        vector<TreeNode*> pre;
        preorder(root,pre);
        for(int i=0;i<pre.size();i++)
        {
            if(i+1<pre.size())
            {
                pre[i]->left = NULL;
                pre[i]->right = pre[i+1];
            }
            else
            {
                pre[i]->left=NULL;
                pre[i]->right=NULL;
            }
        }
    }
};

//USING MORRIS TRANVERSAL
// APPROACH: connected for every subtree its left se rightest node to roots ->right one
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
