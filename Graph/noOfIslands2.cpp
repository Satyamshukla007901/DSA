//https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands
//{ Driver Code Starts
// Initial Template for C++

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
  bool isValid(int x,int y,int n,int m)
  {
      return x>=0 and x<n and y>=0 and y<m;
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        vector<int> ans;
        for(auto &value:operators)
        {
            int row = value[0];
            int col = value[1];
            if(vis[row][col])
            {
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col]=1;
            cnt++;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            for(int ind=0;ind<4;ind++)
            {
                int adjr = row+dr[ind];
                int adjc = col+dc[ind];
                if(isValid(adjr,adjc,n,m))
                {
                    if(vis[adjr][adjc])
                    {
                        int nodeno = row*m+col;
                        int adjno = adjr*m+adjc;
                        if(ds.findPar(nodeno)!=ds.findPar(adjno))
                        {
                            cnt--;
                            ds.Union(nodeno,adjno);
                        }
                    }
                }
            }
            ans.push_back(cnt);
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
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends