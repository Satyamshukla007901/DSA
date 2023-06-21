//https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
// TC - O(N)
// SC - O(1)



// for the successor 
Node* succ = NULL;
while(root)
{
    if(p->val>=root->val)
    {
        root=root->right;
    }
    else
    {
        succ = root;
        root=root->left;
    }
}

return succ;


// for the predecessor

Node* pre = NULL;
while(root)
{
    if(root->val<=p->val)
    {
        pred = root;
        root = root->right;
    }
    else
    {
        root=root->left;
    }
}