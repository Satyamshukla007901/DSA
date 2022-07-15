//https://leetcode.com/problems/redundant-connection/submissions/
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        int par[N+1];
        int rank[N+1];
        for(int i=1;i<=N;i++)
        {
            par[i]=i;
            rank[i]=1;
        }
        
        for(auto &value:edges)
        {
            if(find(value[0],par) == find(value[1],par)) return {value[0],value[1]};
            else union_(value[0],value[1],par,rank);
        }
        return {};
    }
};