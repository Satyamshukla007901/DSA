//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
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
    TreeNode* solve(int i,int j,vector<int> &nums)
    {
        if(i>j) return NULL;
        // else if(i<0 or j>=nums.size()) return NULL;
        int sz = (i+j)/2;
        TreeNode* root = new TreeNode(nums[sz]);
        root->left = solve(i,sz-1,nums);
        root->right = solve(sz+1,j,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       /*
        int size = nums.size();
        if(size==0)
                return NULL;
        
        TreeNode* root = new TreeNode(nums[size/2]);
        vector<int> lvp;
        for(int i=0;i<size/2;i++)
                lvp.push_back(nums[i]);
        
                
        root->left = sortedArrayToBST(lvp);
        vector<int> rvp;
        for(int i=size/2+1;i<size;i++)
                rvp.push_back(nums[i]);
        
        root->right = sortedArrayToBST(rvp);
        return root;*/
        int i = 0;
        int j = nums.size()-1;
        return solve(i,j,nums);
    }
};