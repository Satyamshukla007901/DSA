//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* solve(vector<int> &in,int s,int e,vector<int> &p,unordered_map<int,int> &mp,int &idx)
    {
        if(s>e)
                return NULL;
        if(idx==-1)
                return NULL;
        int index = mp[p[idx--]];
       
        TreeNode* root = new TreeNode(in[index]);
//         We decrement postIdx and recurse to build the right sub-tree and then left sub-tree.
// Why right first? Because postorder goes as left->right->root and we are traversing it from end. So we consider in order root->right->left)
        
        root->right = solve(in,index+1,e,p,mp,idx);
        root->left = solve(in,s,index-1,p,mp,idx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
                mp[inorder[i]]=i;
        int idx =  postorder.size()-1;
        return solve(inorder,0,inorder.size()-1,postorder,mp,idx);
    }
};