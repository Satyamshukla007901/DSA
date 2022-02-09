//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
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
        bool flag = false;
        vector<TreeNode*> a;
        unordered_set<int> s;

        path(root,a,flag,p->val);
        for(auto &value:a)
                s.insert(value->val);
        vector<TreeNode*> b;
        flag = false;
        path(root,b,flag,q->val);
        /*
        for(auto &value:a)
                cout<<value->val<<" ";
        cout<<endl;
        for(auto &value:b)
                cout<<value->val<<" ";
        cout<<endl;*/
        for(auto &value:b)
        {
            if(s.find(value->val)!=s.end())
                    return value;
        }
        return NULL;
        
    }