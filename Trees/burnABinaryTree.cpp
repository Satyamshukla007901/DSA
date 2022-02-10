//https://practice.geeksforgeeks.org/problems/burning-tree/1
void parent(Node *root, unordered_map<Node *, Node *> &p)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 1; i <= sz; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                p[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                p[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
}
void search(Node *root, int target, Node *&t)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == target)
    {
        t = root;
        return;
    }
    search(root->left, target, t);
    search(root->right, target, t);
}
int minTime(Node *root, int t)
{
    unordered_map<Node *, Node *> p;
    parent(root, p);
    Node *target = NULL;
    search(root, t, target);
    unordered_map<Node *, bool> v;
    queue<Node *> q;
    q.push(target);
    v[target] = true;
    int curr = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 1; i <= sz; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left && !v[curr->left])
            {
                q.push(curr->left);
                v[curr->left] = true;
            }
            if (curr->right && !v[curr->right])
            {
                q.push(curr->right);
                v[curr->right] = true;
            }
            if (p[curr] && !v[p[curr]])
            {
                q.push(p[curr]);
                v[p[curr]] = true;
            }
        }
        curr++;
    }
    return curr - 1;
    // Your code goes here
}