//https://www.interviewbit.com/problems/path-to-given-node/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void slve(TreeNode* root,vector<int> &vp,bool &flag,int B)
{
    if(root==NULL)
        return;
    if(root->val==B)
    {
        flag = true;
    }

    if(!flag)
        slve(root->left,vp,flag,B);
    if(!flag)
        slve(root->right,vp,flag,B);
    if(flag==true)
        vp.push_back(root->val);
    
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A==NULL)
        return ans;
    bool flag = false;
    slve(A,ans,flag,B);
    reverse(ans.begin(),ans.end());
    return ans;
}
