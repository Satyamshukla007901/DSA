//https://www.interviewbit.com/problems/path-to-given-node/
TC-->O(N)
SC-->O(N)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool f(TreeNode* root,int B,vector<int> &ans)
 {
     if(root==NULL) return false;
     
     
     ans.push_back(root->val);
     if(root->val==B) return true;
     
     bool l = f(root->left,B,ans);
     bool r = f(root->right,B,ans);
     
     if(l==false and r==false and ans.size()>0)
     {
         ans.pop_back();
     }
     return l or r;
 }
vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int> ans;
    f(root,B,ans);
    return ans;
}
