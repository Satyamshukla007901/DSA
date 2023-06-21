// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// TC - O(N)
//  Sc - O(1)
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
    void ino(TreeNode* root,vector<int> &in)
    {
        if(root==NULL)return;
        ino(root->left,in);
        in.push_back(root->val);
        ino(root->right,in);
    }
    void solve(TreeNode* root,int &k,int &cnt,int &ans)
    {
        if(root==NULL) return;
        
        solve(root->left,k,cnt,ans);
        k--;
        if(k==0)
        {
            ans = root->val;return;
        }
        solve(root->right,k,cnt,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = 0;
        solve(root,k,cnt,ans);
        return ans;
    }
};