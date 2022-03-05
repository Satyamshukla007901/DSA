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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> in = preorder;
        sort(in.begin(),in.end());
        TreeNode* root = buildTree(preorder,in);
        return root;
    }
    TreeNode* solve(vector<int> &p,vector<int> &in,int &idx,unordered_map<int,int> &mp,int s,int e)
    {
        if(idx==p.size())
                return NULL;
        if(s>e)
                return NULL;
        int index = mp[p[idx++]];
        if(index<s||index>e)
                return NULL;
        int val = in[index];
        TreeNode* root = new TreeNode(val);
        root->left = solve(p,in,idx,mp,s,index-1);
        root->right = solve(p,in,idx,mp,index+1,e);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int idx = 0;
        return solve(preorder,inorder,idx,mp,0,inorder.size()-1);
    }
};