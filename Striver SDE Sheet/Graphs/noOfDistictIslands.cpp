//https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
//TC->O(NxMxlog(NxM))+O(NxMx4)
//SC->O(NxM)


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    void dfs(int x,int y,int xi,int xj,vector<vector<int>> &vis,vector<vector<int>>& grid,vector<pair<int,int>> &ok,vector<int> &dRow,vector<int> &dCol)
    {
        vis[x][y]=1;
        ok.push_back({x-xi,y-xj});
        for(int i=0;i<4;i++)
        {
            int nx = x+dRow[i];
            int ny = y+dCol[i];
            if(nx>=0 and nx<grid.size() and ny>=0 and ny<grid[0].size() and grid[nx][ny]==1 and vis[nx][ny]==0)
            {
                dfs(nx,ny,xi,xj,vis,grid,ok,dRow,dCol);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> s;
        int n = grid.size();
        int m = grid[0].size();
  vector<int> dRow = {-1,0,1,0};
  vector<int> dCol = {0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]==1)
                {
                    vector<pair<int,int>> ok;
                    dfs(i,j,i,j,vis,grid,ok,dRow,dCol);
                    s.insert(ok);
                }
            }
        }
        
        return s.size();
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends