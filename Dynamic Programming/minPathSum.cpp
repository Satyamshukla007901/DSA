https://leetcode.com/problems/minimum-path-sum/submissions/
class Solution {
public:
    int solve(int x,int y,vector<vector<int>> &vp,vector<vector<int>> &dp)
    {
        if(x==0&&y==0)
        {
            return vp[0][0];
        }
        else if(x<0||y<0)
        {
            return INT_MAX;
        }
        if(dp[x][y]!=-1)
                return dp[x][y];
        return dp[x][y]=vp[x][y]+min(solve(x-1,y,vp,dp),solve(x,y-1,vp,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<long long>> dp(grid.size(),vector<long long>(grid[0].size(),-1));
        // return solve(grid.size()-1,grid[0].size()-1,grid,dp);
        dp[0][0]=grid[0][0];
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==0&&j==0)
                        continue;
                int up = INT_MAX;
                int left = INT_MAX;
                if(i-1>=0)
                {
                    up = dp[i-1][j];
                }
                if(j-1>=0)
                {
                    left = dp[i][j-1];
                }
                if(i-1>=0&&j-1>=0)
                    dp[i][j] = grid[i][j]+min(left,up);
                else if(i-1>=0)
                    dp[i][j]=grid[i][j]+up;
                else if(j-1>=0)
                {
                    dp[i][j] = grid[i][j]+left;
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};