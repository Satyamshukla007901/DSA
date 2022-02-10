//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/submissions/
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
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &p)
    {
        if(root==NULL)
                return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=1;i<=sz;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)
                {
                    p[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    p[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL)
                return ans;
        unordered_map<TreeNode*,TreeNode*> p;
        parent(root,p);
        unordered_map<TreeNode*,bool> v;
        queue<TreeNode*> q;
        q.push(target);
        v[target]=true;
        int curr  = 0;
        while(!q.empty())
        {
            int sz = q.size();
            if(curr==k)
                    break;
            
            for(int i=1;i<=sz;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left&&!v[curr->left])
                {
                    q.push(curr->left);
                    v[curr->left]=true;
                }
                if(curr->right&&!v[curr->right])
                {
                    q.push(curr->right);
                    v[curr->right]=true;
                }
                if(p[curr]&&!v[p[curr]])
                {
                    q.push(p[curr]);
                    v[p[curr]]=true;
                }
            }
            curr++;
        }
        
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
};