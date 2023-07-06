//https://leetcode.com/problems/course-schedule/
//TC->O(N+2E)
//SC->O(N)
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
        
        map<int,vector<int>> mp;
        for(auto &value:p)
        {
            mp[value[1]].push_back(value[0]);
        }
        
        vector<int> ok(N,0);
        vector<int> d(N,0);
        for(int i=0;i<N;i++)
        {
            if(ok[i]==0)
            {
                if(dfs(i,ok,mp,d)) return false;
            }
        }
        return true;
    }