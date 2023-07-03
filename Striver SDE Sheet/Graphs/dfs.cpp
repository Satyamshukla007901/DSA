//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
//TC->O(N+E)
//SC->O(N+E)

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(int i,vector<int> adj[],vector<int> &ok,vector<int> &dfs)
    {
        
        ok[i]=1;
        dfs.push_back(i);
        for(auto &value:adj[i])
        {
            if(ok[value]==0)
                solve(value,adj,ok,dfs);
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ok(V,0);
        vector<int> dfs;
        solve(0,adj,ok,dfs);
        return dfs;
        // Code here
    }
};