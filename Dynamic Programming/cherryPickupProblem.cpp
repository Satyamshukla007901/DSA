//https://leetcode.com/problems/cherry-pickup-ii/submissions/
class Solution {
public:
    int solve(int i,int j1,int j2,vector<vector<int>> &vp,vector<vector<vector<int>>> &dp)
    {
        if(j1<0||j1>=vp[0].size()||j2<0||j2>=vp[0].size())
        {
            return -1e8;
        }
        else if(i==vp.size()-1)
        {
            if(j1==j2)
                return vp[i][j1];
            else
                return vp[i][j1]+vp[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
                return dp[i][j1][j2];
        int maxi = 0;
        for(int dj1 = -1;dj1<=1;dj1++)
        {
            for(int dj2 = -1;dj2<=1;dj2++)
            {
                if(j1==j2)
                {
                    maxi = max(maxi,vp[i][j1]+solve(i+1,j1+dj1,j2+dj2,vp,dp));
                }
                else
                {
                    maxi = max(maxi,vp[i][j1]+vp[i][j2]+solve(i+1,j1+dj1,j2+dj2,vp,dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return solve(0,0,grid[0].size()-1,grid,dp);
    }
};

// now its time for bottom up approach