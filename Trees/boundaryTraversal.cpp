//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#
    void leftTree(Node* root,vector<int> &ans)
    {
        if(root==NULL)
            return;
        else if(root->left==NULL&&root->right==NULL)
            return;
        if(!(root->left==NULL&&root->right==NULL))
            ans.push_back(root->data);
        if(root->left==NULL)
        {
            leftTree(root->right,ans);
        }
        leftTree(root->left,ans);
    }
    void leafNodes(Node* root,vector<int> &ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
            ans.push_back(root->data);
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
    void rightTree(Node* root,vector<int> &ans)
    {
        if(root==NULL)
            return;
        else if(root->left==NULL&&root->right==NULL)
            return;

        if(root->right==NULL)
        {
            rightTree(root->left,ans);
        }
        rightTree(root->right,ans);
        if(!(root->left==NULL&&root->right==NULL))
            ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        if(root->left==NULL&&root->right==NULL)
            return ans;
        leftTree(root->left,ans);
        leafNodes(root,ans);
        rightTree(root->right,ans);
        return ans;
        //Your code here
    }