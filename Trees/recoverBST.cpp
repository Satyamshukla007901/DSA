//https://leetcode.com/problems/recover-binary-search-tree/submissions/
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
    void inorder(TreeNode* root,vector<TreeNode*> &vp)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,vp);
        vp.push_back(root);
        inorder(root->right,vp);
        
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vp;
        inorder(root,vp);
        vector<int> ok;
        for(auto &value:vp)
        {
            ok.push_back(value->val);
        }
        sort(ok.begin(),ok.end());
        int a = -1;int b = -1;
        for(int i=0;i<vp.size();i++)
        {
            if(vp[i]->val!=ok[i])
            {
                b=vp[i]->val;
                a=ok[i];
                vp[i]->val=ok[i];break;
            }
            else
            {
                
            }
        }
        for(int i=vp.size()-1;i>=0;i--)
        {
            if(vp[i]->val==a)
            {
                vp[i]->val=b;
                break;
            }
        }
    }
};