//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
//TC->O(N)
//SC->O(N)

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
 class BSTIterator{
     stack<TreeNode*> st;
     bool rev = true;
     public:
     BSTIterator(TreeNode* root,bool isRev)
     {
         rev = isRev;
         pushF(root);
     }
     bool hasNext()
     {
         return st.size()>0;
     }
     int next()
     {
         TreeNode* t = st.top();
         st.pop();
         if(rev)
         {
             pushF(t->left);
         }
         else
         {
             pushF(t->right);
         }
         return t->val;
     }
     private:
     void pushF(TreeNode* root)
     {
         while(root)
         {
             st.push(root);
             if(rev)
             {
                 root=root->right;
             }
             else
             {
                 root=root->left;
             }
         }
     }
 };
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &vp)
    {
        
        if(root==NULL)
                return;
        
        inorder(root->left,vp);
        vp.push_back(root->val);
        inorder(root->right,vp);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
                return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j =r.next();
        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
        // vector<int> vp;
        // inorder(root,vp);
        // int start=0;
        // int end = vp.size()-1;
        // while(start<end)
        // {
        //     if(vp[start]+vp[end]==k)
        //             return true;
        //     else if(vp[start]+vp[end]>k)
        //             end--;
        //     else
        //             start++;
        // }
        // return false;
        
    }
};
