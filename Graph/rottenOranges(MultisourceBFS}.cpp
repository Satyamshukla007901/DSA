//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1/?page=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        int N = grid.size();
        int M = grid[0].size();
        int vis[N][M];
        int lev[N][M];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});vis[i][j] = 1;
                    lev[i][j]=0;
                }
                else if(grid[i][j]==0)
                {
                    vis[i][j] = 1;
                    lev[i][j] = -1e9;    
                }
                else
                {
                    vis[i][j] = 0;
                    lev[i][j] = -1e9;  
                }

            }
        }
        int ans = INT_MIN;
        if(q.empty())
        {
            return -1;
        }
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            for(auto &value:mv)
            {
                int cx = x.first+value.first;
                int cy = x.second+value.second;
                if(cx<0 || cy<0 || cx>=N || cy>=M) continue;
                if(vis[cx][cy]==1) continue;
                
                q.push({cx,cy});
                vis[cx][cy] = 1;
                lev[cx][cy] = lev[x.first][x.second]+1;
                // ans = max(ans,lev[cx][cy]);
            }
        }
        /*
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0) return -1;
                ans = max(ans,lev[i][j]);
                // cout<<lev[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans;
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends