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
//Convert Sorted Array to BST
TreeNode *utility(vector<int> &vp, int i, int f)
{
    if (i > f)
        return NULL;
    int mid = (i + f) / 2;
    TreeNode *root = new TreeNode(vp[mid]);
    root->left = utility(vp, i, mid - 1);
    root->right = utility(vp, mid + 1, f);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{

    int size = nums.size();
    if (size == 0)
        return NULL;

    return utility(nums, 0, size - 1);
}
//Minimum Depth of Binray Tree
int minDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right != NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL && root->left != NULL)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
//Invert Tree
TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
//Path Sum
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL && targetSum == 0)
        return false;
    if (root == NULL)
        return false;
    bool l = hasPathSum(root->left, targetSum - (root->val));
    bool r = hasPathSum(root->right, targetSum - (root->val));
    if (targetSum - (root->val) == 0 && root->left == NULL && root->right == NULL)
        return true;
    return l || r;
}
//LCA in BST
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    if ((p->val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val))
    {
        return root;
    }
    else if (p->val == root->val || q->val == root->val)
    {
        return root;
    }
    else if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    return lowestCommonAncestor(root->right, p, q);
}
//Binary Tree paths
void utility(TreeNode *root, vector<string> &vp, string str)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        str += to_string(root->val);
        vp.push_back(str);
    }
    else
        str += to_string(root->val) + "->";

    utility(root->left, vp, str);
    utility(root->right, vp, str);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> vp;
    if (root == NULL)
        return vp;
    string str = "";
    utility(root, vp, str);
    return vp;
}
//Sum of Left Leaves
int utility(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    int lc = utility(root->left);

    int rc = utility(root->right);
    if (root->right && root->right->left == NULL && root->right->right == NULL)
        return lc;
    return lc + rc;
}
int sumOfLeftLeaves(TreeNode *root)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return utility(root);
}
//Finding Mode of a BST
void utility(TreeNode *root, map<int, int> &ump)
{
    if (root == NULL)
        return;
    ump[root->val]++;
    utility(root->left, ump);
    utility(root->right, ump);
    return;
}
vector<int> findMode(TreeNode *root)
{
    vector<int> vp;
    if (root == NULL)
        return vp;

    map<int, int> mp;
    utility(root, mp);
    multimap<int, int, greater<int>> ump;
    for (auto &value : mp)
    {
        ump.insert({value.second, value.first});
    }
    int max = ((*(ump.begin())).first);
    for (auto &value : ump)
    {
        if (value.first == max)
            vp.push_back(value.second);
        else
            break;
    }
    return vp;
}
//Minimum absolute difference in BST
vector<int> vp;
vector<int> inOrder(TreeNode *root)
{
    if (root == NULL)
        return vp;

    vp = inOrder(root->left);
    vp.push_back(root->val);
    vp = inOrder(root->right);
    return vp;
    // Your code here
}
int getMinimumDifference(TreeNode *root)
{
    int mine = INT_MAX;
    vector<int> ok = inOrder(root);
    for (int i = 0; i < ok.size() - 1; i++)
    {
        mine = min(mine, abs(ok[i] - ok[i + 1]));
    }
    return mine;
}
//Better Approach
int mine = INT_MAX;
int val = -1;
int getMinimumDifference(TreeNode *root)
{

    if (root->left)
        getMinimumDifference(root->left);
    if (val >= 0)
        mine = min(mine, abs(root->val - val));
    val = root->val;
    if (root->right)
        getMinimumDifference(root->right);
    return mine;
}
//Binary Tree Tilt
int utility(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    int sumL = 0;
    if (root->left)
        sumL += utility(root->left, ans);
    int sumR = 0;
    if (root->right)
        sumR += utility(root->right, ans);
    ans += abs(sumL - sumR);
    return sumL + sumR + root->val;
}
int findTilt(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    utility(root, ans);
    return ans;
}
//Max Path Sum
int utility(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int Lsum = utility(root->left, maxi);
    int Rsum = utility(root->right, maxi);
    if (Lsum < 0)
        Lsum = 0;
    if (Rsum < 0)
        Rsum = 0;
    maxi = max(maxi, root->val + Lsum + Rsum);

    return root->val + max(Lsum, Rsum);
}
int maxPathSum(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int maxi = INT_MIN;
    utility(root, maxi);
    return maxi;
}
//Tree to String
string tree2str(TreeNode *root)
{
    string str = "";
    if (root == NULL)
        return str;
    str += to_string(root->val);

    if (root->left)
    {
        str += "(";
        str += tree2str(root->left);
        str += ")";
    }
    if ((root->left == NULL && root->right != NULL))
        str += "()";
    if (root->right)
    {
        str += "(";
        str += tree2str(root->right);
        str += ")";
    }

    return str;
}
//Merge trees
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        if (root1 == NULL)
            return root2;
        return root1;
    }
    if (root1->left == NULL && root2->left != NULL)
    {
        TreeNode *node = new TreeNode(root2->left->val);
        root2->left->val = 0;
        root1->left = node;
    }

    if (root1->right == NULL && root2->right != NULL)
    {
        TreeNode *node = new TreeNode(root2->right->val);
        root2->right->val = 0;
        root1->right = node;
    }

    root1->val += root2->val;

    mergeTrees(root1->left, root2->left);
    mergeTrees(root1->right, root2->right);
    return root1;
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
