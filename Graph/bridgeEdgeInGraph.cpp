//https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1/?page=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int i,int p,vector<int> &ok,vector<int> &tin,vector<int> &low,int t,vector<int> adj[],set<pair<int,int>> &s)
    {
        ok[i]=1;
        tin[i] = low[i] = t++;
        for(auto &value:adj[i])
        {
            if(value==p) continue;
            
            if(ok[value]==0)
            {
                dfs(value,i,ok,tin,low,t,adj,s);
                low[i] = min(low[i],low[value]);
                if(low[value]>tin[i])
                {
                    s.insert({i,value});
                    s.insert({value,i});
                }
            }
            else
            {
                low[i] = min(low[i],tin[value]);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
      
        set<pair<int,int>> s;
        int t = 0;
        vector<int> tin(V,-1);
        vector<int> low(V,-1);
        vector<int> ok(V,0);
        for(int i=0;i<V;i++)
        {
            if(ok[i]==0)
            {
                dfs(i,-1,ok,tin,low,t,adj,s);
            }
        }
        // for(auto &value:s)
        // {
        //     cout<<value.first<<" "<<value.second<<endl;
        // }
        if(s.find({c,d}) == s.end()) return 0;
        return 1;
        // Code here
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends