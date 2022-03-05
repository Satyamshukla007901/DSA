//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    void inorder(TreeNode* root,vector<int> &vp)
    {
        
        if(root==NULL)
                return;
        
        inorder(root->left,vp);
        vp.push_back(root->val);
        inorder(root->right,vp);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
                return false;
        vector<int> vp;
        inorder(root,vp);
        int start=0;
        int end = vp.size()-1;
        while(start<end)
        {
            if(vp[start]+vp[end]==k)
                    return true;
            else if(vp[start]+vp[end]>k)
                    end--;
            else
                    start++;
        }
        return false;
        
    }
};