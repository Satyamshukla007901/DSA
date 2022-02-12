//https://leetcode.com/problems/count-complete-tree-nodes/submissions/
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
    int leftHeight(TreeNode* root)
    {
        if(!root)return NULL;
        
        int cnt = 0;
        while(root)
        {
            root=root->left;
            cnt++;
        }
        return cnt;
    }
    int rightHeight(TreeNode* root)
    {
        if(!root)return NULL;
        
        int cnt = 0;
        while(root)
        {
            root=root->right;
            cnt++;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
                return 0;
        //TC - O(N)
        // return 1+countNodes(root->left)+countNodes(root->right);
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh==rh)return (1<<lh)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};