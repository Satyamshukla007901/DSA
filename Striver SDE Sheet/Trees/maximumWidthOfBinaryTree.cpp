//https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
                return 0;
        int ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int sz = q.size();
            int minm = q.front().second;
            int f,l;
            for(int i=0;i<sz;i++)
            {
                long long curr = q.front().second-minm;
                TreeNode* node = q.front().first;
                
                if(i==0)f = q.front().second;
                if(i==sz-1)l = q.front().second;
                q.pop();
                if(node->left)
                        q.push({node->left,curr*2+1});
                if(node->right)
                        q.push({node->right,curr*2+2});
            }
            ans=max(ans,l-f+1);
        }
        return ans;
        
    }
};