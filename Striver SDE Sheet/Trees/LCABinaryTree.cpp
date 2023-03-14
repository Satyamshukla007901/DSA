// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// TC -- O(N)
// SC -- O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void path(TreeNode* root,vector<TreeNode*> &vp,bool &flag,int B)
{
    if(root==NULL)
        return;
    if(root->val==B)
    {
        flag = true;
    }

    if(!flag)
        path(root->left,vp,flag,B);
    if(!flag)
        path(root->right,vp,flag,B);
    if(flag==true)
        vp.push_back(root);
    
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
                return NULL;
                // TC - O(2N) SC - O(3N)
        // bool flag = false;
        // vector<TreeNode*> a;
        // unordered_set<int> s;

        // path(root,a,flag,p->val);
        // for(auto &value:a)
        //         s.insert(value->val);
        // vector<TreeNode*> b;
        // flag = false;
        // path(root,b,flag,q->val);
        
        // for(auto &value:a)
        //         cout<<value->val<<" ";
        // cout<<endl;
        // for(auto &value:b)
        //         cout<<value->val<<" ";
        // cout<<endl;
        // for(auto &value:b)
        // {
        //     if(s.find(value->val)!=s.end())
        //             return value;
        // }
        // return NULL;


        //TC - O(N) SC-O(N)

        if(root->val==p->val or root->val==q->val) return root;

        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        if(!l) return r;
        else if(!r) return l;
        return root;




        
    }
};