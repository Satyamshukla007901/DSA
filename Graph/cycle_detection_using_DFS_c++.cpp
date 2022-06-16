// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
//  { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> ok(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (ok[i] == 0)
            {
                queue<pair<int, int>> q;
                q.push({i, -1});
                ok[i] = 1;
                while (!q.empty())
                {
                    auto node = q.front();
                    q.pop();
                    for (auto &value : adj[node.first])
                    {
                        if (ok[value] == 1 and node.second != value)
                        {
                            return true;
                        }
                        else if (ok[value] == 0)
                        {
                            q.push({value, node.first});
                            ok[value] = 1;
                        }
                    }
                }
            }
        }

        return false;
        // Code here
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends