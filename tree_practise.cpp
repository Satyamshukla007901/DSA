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
