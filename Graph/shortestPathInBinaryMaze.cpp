//https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
    
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int cnt = 0;
        queue<pair<int,pair<int,int>>> q;
        
        q.push({source.first,{source.second,0}});
        if(grid[source.first][source.second]==0 or grid[destination.first][destination.second]==0) return -1;
        vis[source.first][source.second]=1;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second.first;
            int l = q.front().second.second;
            q.pop();
            if(x==destination.first and y==destination.second) return l;
            //
            if(x-1>=0 and grid[x-1][y]==1 and vis[x-1][y]==0){ q.push({x-1,{y,l+1}});vis[x-1][y]=1;}
            if(y+1<grid[0].size() and grid[x][y+1]==1 and vis[x][y+1]==0){ q.push({x,{y+1,l+1}});vis[x][y+1]=1;}
            if(x+1<grid.size() and grid[x+1][y]==1 and vis[x+1][y]==0){ q.push({x+1,{y,l+1}});vis[x+1][y]=1;}
            if(y-1>=0 and grid[x][y-1]==1 and vis[x][y-1]==0){ q.push({x,{y-1,l+1}});vis[x][y-1]=1;}
            
            
            cnt++;
            
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends