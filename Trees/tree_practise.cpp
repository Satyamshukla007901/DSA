#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void preorder(struct Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(struct Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> vp;
    if (root == NULL)
        return vp;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> t;
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *temp = q.front();
            // cout<<temp->val<<" ";
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            t.push_back(temp->val);
        }
        cout << endl;
        vp.push_back(t);
    }
    return vp;
}
//Preoorder iterative
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> vp;
    if (!root)
        return vp;

    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *temp = st.top();
        st.pop();

        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
        vp.push_back(temp->val);
    }
    return vp;
}
//Inorder Iterative
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> vp;
    if (root == NULL)
        return vp;

    stack<TreeNode *> st;
    TreeNode *temp = root;

    while (1)
    {

        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            vp.push_back(st.top()->val);
            temp = st.top();
            st.pop();

            temp = temp->right;
        }
        if (st.empty() == true && temp == NULL)
            break;
    }
    return vp;
}
//Postorder iterative Approach using 2 stacks
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> vp;
    if (root == NULL)
        return vp;

    stack<TreeNode *> sp;
    sp.push(root);
    stack<TreeNode *> ans;
    while (!sp.empty())
    {
        TreeNode *item = sp.top();
        sp.pop();
        ans.push(item);
        if (item->left)
            sp.push(item->left);
        if (item->right)
            sp.push(item->right);
    }
    while (!ans.empty())
    {
        vp.push_back(ans.top()->val);
        ans.pop();
    }
    return vp;
}
//Tree HEight
int maxDepth(TreeNode *root)
{
    int count = 0;
    if (root == NULL)
        return count;

    count += 1 + max(maxDepth(root->left), maxDepth(root->right));
    return count;
}
//Tree is Balanced or not check
//O(N) TC
//SC - O(N)
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
bool isBalanced(TreeNode *root)
{

    if (root == NULL)
        return true;

    if (height(root) == -1)
        return false;
    return true;
}
//TC - O(N^2)
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(TreeNode *root)
{

    if (root == NULL)
        return true;

    int lheight = height(root->left);
    int rheight = height(root->right);

    if (abs(lheight - rheight) <= 1)
        return isBalanced(root->left) && isBalanced(root->right);
    else
        return false;
}
//Diameteer of Binary Tree
//Brute FOrce
//TC-> O(N^2)
int path(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(path(root->left), path(root->right));
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int sum = path(root->left) + path(root->right);
    return max(sum, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}
//O(N) approach
int path(TreeNode *root, int &x)
{
    if (root == NULL)
        return 0;

    int lh = path(root->left, x);
    int rh = path(root->right, x);
    x = max(x, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int x = 0;
    path(root, x);
    return x;
}
//is Symmetric
bool same(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (!p || !q)
        return false;

    return (p->val == q->val) && same(p->left, q->right) && same(p->right, q->left);
}
bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;

    return same(root->left, root->right);
}
int32_t main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //preorder traversal
    preorder(root);
    cout << endl;

    //inorder traversal
    inorder(root);
    cout << endl;

    //postorder traversal
    postorder(root);
    cout << endl;

    //levelOrder traversal
    levelOrder(root);
    cout << endl;
}
