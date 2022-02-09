//https://leetcode.com/problems/symmetric-tree/
    bool same(TreeNode *p,TreeNode *q)
    {
        if(p==NULL&&q==NULL)
                return true;
        if(!p||!q)
                return false;
        
        return (p->val==q->val)&&same(p->left,q->right)&&same(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
                return true;
        
        return same(root->left,root->right);
    }