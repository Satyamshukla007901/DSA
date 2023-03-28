//https://leetcode.com/problems/validate-binary-search-tree/
// TC->O(N)
//  SC->O(N)

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
//     void inorder(TreeNode* root,vector<int>&ok)
//     {
//         if(root==NULL)
//                 return;
        
//         inorder(root->left,ok);
//         ok.push_back(root->val);
//         inorder(root->right,ok);
//     }
bool solve(TreeNode* root,long long l,long long r)
{
    if(root==NULL) return true;
    
    if(root->val<=l or root->val>=r) return false;
    
    return solve(root->left,l,root->val) and solve(root->right,root->val,r);
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
                return true;
        return solve(root,LONG_MIN,LONG_MAX);
        // vector<int> ok;
        // inorder(root,ok);
        // for(int i = 0;i<ok.size();i++)
        // {
        //     if(i+1<ok.size()&&ok[i]>=ok[i+1])
        //     {
        //         return false;
        //     }
        // }
        // return true;
        
        
    }
};
