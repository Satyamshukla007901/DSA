//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
//TC->O(N+2E)
//SC->O(N+E)

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ok(V,0);
        queue<int> q;
        ok[0]=1;
        vector<int> bfs;
        q.push(0);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto &value:adj[node])
            {
                if(ok[value]==0)
                {q.push(value);ok[value]=1;}
                
            }
        }
        return bfs;
        // Code here
    }
};
