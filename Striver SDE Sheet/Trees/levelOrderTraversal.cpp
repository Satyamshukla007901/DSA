//https://leetcode.com/problems/binary-tree-level-order-traversal/
TC->O(N)
SC->O(N)
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vp;
        if(root == NULL)
            return vp;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> t;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp = q.front();
                // cout<<temp->val<<" ";
                q.pop();
                if(temp->left!=NULL){q.push(temp->left);}
                if(temp->right!=NULL){q.push(temp->right);}
                t.push_back(temp->val);               
            }
            cout<<endl;
            vp.push_back(t);
        }
        return vp;
    }
};