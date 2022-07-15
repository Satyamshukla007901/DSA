//https://leetcode.com/problems/network-delay-time/submissions/
class Solution {
public:
    vector<int> djiktras(int src,map<int,vector<pair<int,int>>> &mp,int N)
    {
        vector<int> ans(N+1,INT_MAX);
        ans[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty())
        {
            int d = pq.top().first;
            int x = pq.top().second;pq.pop();
            for(auto &value:mp[x])
            {
                int n = value.first;
                int w = value.second;
                if(w+d<ans[n])
                {
                    ans[n]=w+d;
                    pq.push({ans[n],n});
                }
            }
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>> mp;
        for(auto &value:times)
        {
            mp[value[0]].push_back({value[1],value[2]});
        }
        vector<int> ans = djiktras(k,mp,n);
        int ok = ans[1];
        for(int i=1;i<=n;i++)
        {
            int value = ans[i]; 
            ok=max(value,ok);
        }
        if(ok==INT_MAX) return -1;
        return ok;
    }
};