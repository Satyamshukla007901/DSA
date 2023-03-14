#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int N)
    {
        rank.resize(N+1,0);
        parent.resize(N+1);
        size.resize(N+1);
        for(int i=0;i<=N;i++)
        {
            parent[i]=i;size[i]=1;
        }
    }
    int findPar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }

    void Union(int u,int v)
    {
        int ult_u  = findPar(u);
        int ult_v = findPar(v);
        if(ult_u == ult_v) return;

        if(rank[ult_u]<rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v]<rank[ult_u])
        {
            parent[ult_v] = ult_u;
        }
        else
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
    void unionBySize(int u,int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu==pv)
        {
            return;
        }

        if(size[pu]<size[pv])
        {
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
};

int32_t main()
{
    DisjointSet d(7);
}