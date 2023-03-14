//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
    vector<int> rank,parent;
    
    DisjointSet(int N)
    {
        rank.resize(N+1,0);
        parent.resize(N+1);
        for(int i=0;i<=N;i++)
        {
            parent[i]=i;
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
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet d(n);
        int cnt = 0;
        int ans = 0;
        for(auto &value:edge)
        {
            if(d.findPar(value[0])==d.findPar(value[1]))
            {
                cnt++;
            }
            else
            {
                d.Union(value[0],value[1]);
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(d.parent[i]==i) ans++;
        }
        --ans;
        return cnt>=ans?ans:-1;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends