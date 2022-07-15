//https://leetcode.com/problems/minimum-height-trees/submissions/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> in(n,0);
        map<int,vector<int>> mp;
        for(auto &value:edges)
        {
            in[value[0]]++;
            in[value[1]]++;
            mp[value[0]].push_back(value[1]);
            mp[value[1]].push_back(value[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            // cout<<in[i]<<" ";
            if(in[i]==1)
            {
                q.push(i);
            }
        }
        // cout<<endl;
         
        while(n>2)
        {
            n-=q.size();
            int sz = q.size();
            while(sz-->0)
            {
                int node = q.front();
                q.pop();
                for(auto &value:mp[node])
                {
                    in[value]--;
                    if(in[value]==1)
                    {
                        q.push(value);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
    }
};