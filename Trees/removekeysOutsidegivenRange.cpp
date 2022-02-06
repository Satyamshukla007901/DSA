//https://practice.geeksforgeeks.org/problems/remove-bst-keys-outside-given-range/1#
    Node* removekeys(Node* root, int l, int r) {
        
        if(root==NULL)return NULL;
        root->left = removekeys(root->left,l,r);
        root->right = removekeys(root->right,l,r);
        if(root->data<l)
        {
            Node* ok = root->right;
            delete root;
            return ok;
        }
        else if(root->data>r)
        {
            Node* ok = root->left;
            delete root;
            return ok;
        }
        return root;
        // code here
            
    }