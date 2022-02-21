//https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?leftPanelTab=1
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> *root,int &ans,int x)
{
    if(root==NULL)
        	return;
    if(root->val<=x)
    {
        if(ans==-1)
        {
            ans=root->val;
        }
        else
            ans=max(ans,root->val);
        solve(root->right,ans,x);
    }
    solve(root->left,ans,x);
}
int floorInBST(TreeNode<int> * root, int x)
{
    int ans = -1;
    solve(root,ans,x);
    return ans;
    // Write your code here.
}