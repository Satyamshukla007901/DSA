//https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    void union_( int a, int b, int par[], int rank[]) 
    {
        a =find(a,par);
        b =find(b,par);
        if(rank[a]<rank[b])
        {
            par[a] = b;
            
        }
        else if(rank[a]>rank[b])
        {
            par[b] = a;
        }
        else
        {
            par[b]=a;
            rank[b]++;
        }
        //code here
    }
    int find(int x,int par[])
    {
        if(x==par[x]) return x;
        
        return par[x] = find(par[x],par);
    }
    void dfs(int x,map<int,vector<int>> &mp,vector<int> &ok)
    {
        ok[x]=1;
        for(auto &value:mp[x])
        {
            if(ok[value]==0)
            {
                dfs(value,mp,ok);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        map<int,vector<int>> mp;
        for(auto &value:connections)
        {
            mp[value[0]].push_back(value[1]);
            mp[value[1]].push_back(value[0]);
        }
        
        int cnt = 0;
        int par[n];
        int rank[n];
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            rank[i]=1;
        }
        int temp = 0;
        for(auto &value:connections)
        {
            if(find(value[0],par)==find(value[1],par))
            {
                temp++;
            }
            else
            {
                union_(value[0],value[1],par,rank);
            }
        }
        vector<int> ok(n,0);
        for(int i=0;i<n;i++)
        {
            if(ok[i]==0){
                cnt++;
                dfs(i,mp,ok);
            }
        }
        if(cnt-1<=temp) return cnt-1;
        return -1;
    }
};