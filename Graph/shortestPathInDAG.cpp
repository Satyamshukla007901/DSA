//https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph
//{ Driver Code Starts
// Initial Template for C++
TC - o(n+m)
SC - o(n)
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(int node,vector<pair<int,int>> adj[],vector<int> &visi,stack<int> &st)
  {
      visi[node]=1;
      for(auto &value:adj[node])
      {
          if(visi[value.first]==0)
          {
              dfs(value.first,adj,visi,st);
          }
      }
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int,int>> adj[N];
         for(int i=0;i<M;i++)
         {
             adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
         }
         vector<int> visi(N,0);
         vector<int> ans(N,1e8);
         stack<int> st;
         for(int i=0;i<N;i++)
         {
             if(visi[i]==0)
             {
                 dfs(i,adj,visi,st);
             }
         }
         
         ans[0]=0;
         while(!st.empty())
         {
             int node = st.top();
             st.pop();
             for(auto &value:adj[node])
             {
                 if(ans[node]+value.second<ans[value.first])
                 {
                     ans[value.first] = ans[node]+value.second;
                 }
             }
         }
         for(auto &value:ans)
         {
             if(value==1e8) value=-1;
         }
         return ans;
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
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends