//https://leetcode.com/problems/binary-tree-inorder-traversal/
    // TC-->O(N)
    // Sc-->O(N)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vp;
        if(root == NULL)
            return vp;
        
        stack<TreeNode*> st;
        TreeNode* temp = root;
        
        while(1)
        {
            
            if(temp!=NULL)
            {
                st.push(temp);
                temp=temp->left;
            }
            else
            {   
                vp.push_back(st.top()->val);
                temp=st.top();
                st.pop();

                temp=temp->right;
            } 
            if(st.empty()==true&&temp==NULL)
                    break;
        }
        return vp;
    }
// TC-->O(N) SC-->O(N)
    vector<int> vp;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
            return vp;
        vp = inorderTraversal(root->left);
        vp.push_back(root->val);
        vp = inorderTraversal(root->right);
        return vp;
    }