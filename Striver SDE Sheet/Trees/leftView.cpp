//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// TC-->O(N)
// SC-->O(N)
vector<vector<int>> lorder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> ok;
        for(int i=0;i<size;i++)
        {
            Node* node = q.front();q.pop();
            ok.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(ok.size()>0) ans.push_back(ok);
    }
    return ans;
}
vector<int> leftView(Node *root)
{
    if(root==NULL) return {};
    
    vector<vector<int>> ans;
    ans = lorder(root);
    vector<int> ok;
    for(auto &value:ans)
    {
        ok.push_back(value[0]);
    }
    return ok;
   // Your code here
}

// TC-->O(N)
// SC-->O(N)

void f(Node* root,int level,vector<int> &ans)
{
    if(root==NULL) return;
    if(ans.size()==level) ans.push_back(root->val);
    f(root->left,level+1,ans);
    f(root->right,level+1,ans);
}

//for right viiew we just wanna traverse right first then left