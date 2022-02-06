//https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1#
Node* insert(Node* root, int Key) {
    Node* node = newNode(Key);
    if(root==NULL)
        return node;
    
    if(Key<root->data)
    {
        if(root->left)
        {
            insert(root->left,Key);
        }
        else
            root->left=node;
    }
    else if(Key>root->data)
    {
        if(root->right)
        {
            insert(root->right,Key);
        }
        else
        {
            root->right=node;
        }
    }
    return root;
    // Your code here
}
Node* post_order(int pre[], int size)
{
    if(size==0)
        return NULL;
    Node* root = NULL;
    for(int i=0;i<size;i++)
    {
        root = insert(root,pre[i]);
    }
    return root;
    //code here
}