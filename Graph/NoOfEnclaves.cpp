// https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves
// TC-> O(NM) + O(NM)*4
// Sc-> O(NM)

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        //first and last row
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
            {
                vis[0][i] = 1;
                q.push({0,i});
            }
            if(grid[n-1][i]==1)
            {
                vis[n-1][i] = 1;
                q.push({n-1,i});
            }
        }
        
        //first and last column
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                vis[i][0] = 1;
                q.push({i,0});
            }
            if(grid[i][m-1]==1)
            {
                vis[i][m-1] = 1;
                q.push({i,m-1});
            }
            
        }
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nRow = row+dRow[i];
                int nCol = col+dCol[i];
                if(nRow>=0 and nRow<n and nCol>=0 and nCol<m and vis[nRow][nCol]==0 and grid[nRow][nCol]==1)
                {
                    q.push({nRow,nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }
        
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
        
        
        
        // Code here
    }
};


// { Driver Code Starts.

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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}  // } Driver Code Ends