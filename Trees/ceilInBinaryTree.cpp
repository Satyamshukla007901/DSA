//https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?leftPanelTab=1
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void solve(BinaryTreeNode<int> *node,int &ans,int x)
{
    if(node==NULL)
        	return ;
    if(node->data>=x)
    {
        if(ans==-1)
        {
            ans=node->data;
        }
        else
            ans=min(ans,node->data);
        solve(node->left,ans,x);
    }
    solve(node->right,ans,x);
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = -1;
    solve(node,ans,x);
    return ans;
    // Write your code here.
}