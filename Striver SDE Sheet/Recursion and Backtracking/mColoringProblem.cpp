//https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isValid(int c,int node,map<int,vector<int>> &adj,vector<int> &color)
    {
        for(auto &value:adj[node])
        {
            if(color[value]==c) return false;
        }
        return true;
    }
    bool solve(int node,int n,int m,map<int,vector<int>> &adj,vector<int> &color)
    {
        if(node==n)
        {
            return true;
        }
        
        for(int i=1;i<=m;i++)
        {
            if(isValid(i,node,adj,color))
            {
                color[node] = i;
                if(solve(node+1,n,m,adj,color)) return true;
                color[node] = -1;
                
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        map<int,vector<int>> adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> color(n,-1);
        return solve(0,n,m,adj,color);
        // your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Endsbi