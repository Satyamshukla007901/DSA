//https://leetcode.com/problems/flower-planting-with-no-adjacent/submissions/
class Solution {
public:
    void dfs(int x,vector<int> &ok,map<int,vector<int>> &mp,int cnt)
    {
        if(ok[x-1]==-1)
        {    
            vector<bool> temp(5,false);
            for(auto &value:mp[x])
            {
                if(ok[value-1]!=-1)
                {
                    temp[ok[value-1]] = true;
                }
            }
            for(int i=1;i<=4;i++)
            {
                if(temp[i]==false)
                {
                    ok[x-1]=i;
                    break;
                }
            }
        }
        
        for(auto &value:mp[x])
        {
            if(ok[value-1]==-1)
            {
                dfs(value,ok,mp,cnt);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        map<int,vector<int>> adj;
        for(auto &value:paths)
        {
            adj[value[0]].push_back(value[1]);
            adj[value[1]].push_back(value[0]);
        }
        vector<int> color(n,-1);
        /*
        int cnt = 1;
        for(int i=1;i<=n;i++)
        {
            if(color[i-1]==-1)
            {
                
                dfs(i,color,adj,cnt);
            }
        }
        return color;*/
        // more effiecient approach
        //graph coloring
        for(int i=1;i<=n;i++)
        {
            unordered_set<int> s;
            for(auto &value:adj[i])
                s.insert(color[value-1]);
            
            for(int j=1;j<=4;j++)
            {
                if(s.find(j)==s.end())
                {
                    color[i-1] = j;break;
                }
            }
        }
        return color;
    }
};