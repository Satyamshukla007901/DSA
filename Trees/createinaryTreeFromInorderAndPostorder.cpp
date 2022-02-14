///https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/
    TreeNode* solve(vector<int> &in,int s,int e,vector<int> &p,unordered_map<int,int> &mp,int &idx)
    {
        if(s>e)
                return NULL;
        if(idx==-1)
                return NULL;
        int index = mp[p[idx--]];
        if(index<s&&index>e)
                return NULL;
        TreeNode* root = new TreeNode(in[index]);
        root->right = solve(in,index+1,e,p,mp,idx);
        root->left = solve(in,s,index-1,p,mp,idx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
                mp[inorder[i]]=i;
        int idx =  postorder.size()-1;
        return solve(inorder,0,inorder.size()-1,postorder,mp,idx);
    }