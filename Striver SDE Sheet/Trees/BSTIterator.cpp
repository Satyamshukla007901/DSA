//https://leetcode.com/problems/binary-search-tree-iterator/description/
//TC->O(1)
//SC->O(H)


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
class BSTIterator {
    private: 
    stack<TreeNode*> st;
    void pushF(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        return;
    }

public:
    // TreeNode* r;int i=-1;
    // vector<TreeNode*> vp;
    // void inorder(TreeNode* root,vector<TreeNode*> &vp)
    // {
    //     if(root==NULL)
    //             return;
        
    //     inorder(root->left,vp);
    //     vp.push_back(root);
    //     inorder(root->right,vp);
    // }
    BSTIterator(TreeNode* root) {
        
        pushF(root);
        // i=-1;
        // r=root;
        // inorder(root,vp);
    }
    
    int next() {
        TreeNode* t = st.top();
        int ans = st.top()->val;
        st.pop();
        pushF(t->right);
        return ans;
        // i++;
        // if(i==vp.size())
        //         return -1;
        // return vp[i]->val;
    }
    
    bool hasNext() {
        return st.size()>0;
        // return i+1<vp.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */