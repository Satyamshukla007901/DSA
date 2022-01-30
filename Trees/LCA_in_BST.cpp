https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#
Node* LCA(Node *root, int n1, int n2)
{
    if(root==NULL)
        return NULL;
    if(n1>root->data&&n2>root->data)
        return LCA(root->right,n1,n2);
    else if(n1<root->data&&n2<root->data)
        return LCA(root->left,n1,n2);
    return root;
   //Your code here
}

//pth common ancestor
//https://practice.geeksforgeeks.org/problems/pth-common-ancestor-in-bst/1#
void LCA(NODE *root, int n1, int n2,vector<int> &vp)
{
    if(root==NULL)
        return;
    if(n1>root->data&&n2>root->data)
    {
        vp.push_back(root->data);
        LCA(root->right,n1,n2,vp);
        return;
    }
    else if(n1<root->data&&n2<root->data)
    {
        vp.push_back(root->data);
        LCA(root->left,n1,n2,vp);
        return;
    }
    vp.push_back(root->data);
    return;
   //Your code here
}
int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec){
    LCA(root,x,y,vec);
    for(auto &value:vec)
        cout<<value<<" ";
    cout<<endl;
    if(vec.size()<p)
        return -1;
    else
        return vec[vec.size()-p];
     /*Your code here */
}