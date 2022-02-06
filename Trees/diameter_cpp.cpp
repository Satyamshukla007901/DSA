//https://leetcode.com/problems/diameter-of-binary-tree/submissions/
    int path(TreeNode* root,int &x)
    {
        if(root==NULL)return 0;
        
        int lh = path(root->left,x);
        int rh = path(root->right,x);
        x=max(x,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int x=0;
        path(root,x);
        return x;
    }

