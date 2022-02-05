//https://leetcode.com/problems/same-tree/
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL&&q!=NULL)
                return false;
        if(p!=NULL&&q==NULL)
                return false;
        bool c = p->val==q->val;
        bool l = isSameTree(p->left,q->left);
        bool r = isSameTree(p->right,q->right);
        return l&&r&&c;
        
        
        
        }