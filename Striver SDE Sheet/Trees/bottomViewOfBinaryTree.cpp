//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Tc-->O(N)
// SC-->O(N)

        map<int,int> mp;
      
        vector<int> ans;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            Node* node = q.front().first;
            int col = q.front().second;
            mp[col] = node->data;q.pop();
            if(node->left)
            {
                q.push({node->left,col-1});
            }
            if(node->right)
            {
                q.push({node->right,col+1});
            }
        }
        for(auto &value:mp)
        {
            ans.push_back(value.second);
        }
        return ans;