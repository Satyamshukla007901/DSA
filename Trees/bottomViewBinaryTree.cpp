//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
void solve(Node *root, map<int, map<int, vector<int>>> &mp, int cnt, int l)
{
    if (root == NULL)
        return;

    mp[cnt][l].push_back(root->data);
    solve(root->left, mp, cnt - 1, l + 1);
    solve(root->right, mp, cnt + 1, l + 1);
    return;
}
vector<int> bottomView(Node *root)
{
    map<int, map<int, vector<int>>> mp;
    solve(root, mp, 0, 0);
    vector<int> ans;
    if (root == NULL)
        return ans;

    for (auto &value : mp)
    {
        auto it = value.second.end();
        --it;
        ans.push_back(it->second[it->second.size() - 1]);
    }
    return ans;
    // Your Code Here
}