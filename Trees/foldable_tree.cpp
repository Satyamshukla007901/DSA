//https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1#
bool solve(Node* r1,Node* r2)
{
    if(r1==NULL&&r2==NULL)
        return true;
    else if(r1==NULL&&r2!=NULL)
        return false;
    else if(r1!=NULL&&r2==NULL)
        return false;
    else if(r1->left!=NULL&&r1->right==NULL&&r2->left!=NULL&&r2->right==NULL)
        return false;
    else if(r1->right!=NULL&&r1->left==NULL&&r2->left==NULL&&r2->right!=NULL)
        return false;
    else if(r1->left&&r1->right&&r2->left&&r2->right==NULL)
        return false;
    else if(r1->left&&r1->right&&r2->left==NULL&&r2->right)
        return false;
    else if(r1->left&&r1->right==NULL&&r2->left&&r2->right)
        return false;
    else if(r1->left==NULL&&r1->right&&r2->left&&r2->right)
        return false;
    return solve(r1->left,r2->right)&&solve(r1->right,r2->left);
}
bool IsFoldable(Node* root)
{
    if(root==NULL)
        return true;
    else if(root->left&&root->right==NULL)
        return false;
    else if(root->right&&root->left==NULL)
        return false;
    
    Node* r1 = root->left;
    Node* r2 = root->right;
    return solve(r1,r2);
    
    // Your code goes here
}