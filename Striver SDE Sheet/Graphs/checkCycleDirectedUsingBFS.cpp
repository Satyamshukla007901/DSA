//https://leetcode.com/problems/course-schedule/
//TC->O(N+E)
//SC->O(N)

class Solution {
public:
    bool dfs(int x,vector<int> &ok,map<int,vector<int>> &mp,vector<int> &d)
    {
        ok[x] = 1;d[x]=true;
        for(auto &value:mp[x])
        {
            if(ok[value]==0)
            {
                if(dfs(value,ok,mp,d)) return true;
            }
            else if(d[value]) return true;
        }
        d[x]=false;
        return false;
    }
    bool canFinish(int N, vector<vector<int>>& p) {
        
        vector<int> adj[N];
        for(auto &value:p)
        {
            adj[value[1]].push_back(value[0]);
        }
       
        vector<int> in(N,0);
        queue<int> q;
        for(int i=0;i<N;i++)
        {
            for(auto &value:adj[i])
            {
                in[value]++;
            }
        }
        for(int i=0;i<N;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }

        int check = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            check++;
            for(auto &value:adj[node])
            {
                in[value]--;
                if(in[value]==0)
                {
                    q.push(value);
                }
            }
        }
        return check==N;
    }
};