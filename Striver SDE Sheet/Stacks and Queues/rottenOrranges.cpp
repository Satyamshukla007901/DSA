//https://leetcode.com/problems/rotting-oranges/
/*
    TC -- O(n^2)*4
    SC -- O(n^2)
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> mv = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        int N = grid.size();
        int M = grid[0].size();
        // int vis[N][M];
        int lev[N][M];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    // vis[i][j] = 1;
                    lev[i][j]=0;
                }
                else if(grid[i][j]==0)
                {
                    // vis[i][j] = 1;
                    lev[i][j] = -1e9;    
                }
                else
                {
                    // vis[i][j] = 0;
                    lev[i][j] = -1e9;  
                }

            }
        }
        int ans = INT_MIN;
        if(q.empty())
        {
            // bool flag = true;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    if(grid[i][j]==1)
                    {
                        return -1;
                    }
                }
            }
            // if(flag) return 0;
            // return -1;
            return 0;
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
                // if(vis[cx][cy]==1) continue;
                if(grid[cx][cy]==2 or grid[cx][cy]==0) continue;
                grid[cx][cy] = 2;
                q.push({cx,cy});
                // vis[cx][cy] = 1;
                lev[cx][cy] = lev[x.first][x.second]+1;
                
            }
        }
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                // if(grid[i][j]==1 and vis[i][j]==0) return -1;
                if(grid[i][j]==1) return -1;
                ans = max(ans,lev[i][j]);
               
            }
        
        }
        return ans;
    }
};