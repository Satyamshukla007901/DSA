//https://leetcode.com/problems/delete-node-in-a-bst/submissions/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key)
        {
            if(root->left==NULL&&root->right==NULL) return NULL;
            else if(root->left==NULL) return root->right;
            else if(root->right==NULL) return root->left;
            TreeNode* node = root->right;
            while(node->left)
                    node=node->left;
            root->val = node->val;
            root->right = deleteNode(root->right,node->val);
            
            return root;
        }
        if(key<root->val) root->left=deleteNode(root->left,key);
        else
            root->right=deleteNode(root->right,key);
        return root;
    }
};

//
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        
        if(root->val==key)
        {
            return help(root);
        }
        TreeNode* node = root;
        while(node)
        {
            if(key<node->val)
            {
                if(node->left&&node->left->val==key)
                {
                    node->left=help(node->left);break;
                }
                else
                    node=node->left;
            }
            else
            {
                if(node->right&&node->right->val==key)
                {
                    node->right=help(node->right);break;
                }
                else
                    node=node->right;
            }
        }
        return root;
    }
    TreeNode* help(TreeNode* root)
    {
        if(root->left==NULL)
                return root->right;
        else if(root->right==NULL)
                return root->left;
        TreeNode* r = root->right;
        TreeNode* l = root->left;
        while(l&&l->right)
                l=l->right;
        l->right = r;
        return root->left;
    }
};