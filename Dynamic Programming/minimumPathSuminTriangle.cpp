//https://leetcode.com/problems/triangle/submissions/
class Solution {
public:
    int solve(int x,int y,int N,vector<vector<int>> &vp,vector<vector<int>> &dp)
    {
        if(x<0||y<0||y>x)
                return 100000000;
        else if(x==0&&y==0)
        {
            return vp[0][0];
        }
        if(dp[x][y]!=-1)
                return dp[x][y];
        int up;
        int left;
        up = solve(x-1,y-1,N,vp,dp);
        left = solve(x-1,y,N,vp,dp);
        return dp[x][y]=vp[x][y]+min(up,left);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        int maxe = INT_MAX;
        vector<vector<int>> dp(N,vector<int>(N,-1));
        for(int i=0;i<N;i++)
        {
            maxe = min(maxe,solve(N-1,i,N,triangle,dp));
        }
        return maxe;
    }
};


//top down
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        int maxe = INT_MAX;
        /*
        vector<vector<int>> dp(N,vector<int>(N,-1));
        for(int i=0;i<N;i++)
        {
            maxe = min(maxe,solve(N-1,i,N,triangle,dp));
        }
        return maxe;*/
        vector<vector<int>> dp(N,vector<int>(N,-1));
        dp[0][0]=triangle[0][0];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(i==0&&j==0)
                {
                    continue;
                }
                int up = 10000000;
                int left = 10000000;
                if(i-1>=0&&j-1>=0&&j-1<=i-1)
                {
                    left = dp[i-1][j-1];
                }
                if(i-1>=0&&j<=i-1)
                {
                    up = dp[i-1][j];
                }
                dp[i][j] = triangle[i][j]+min(up,left);
            }
        }
        for(int i=0;i<N;i++)
        {
            
            maxe = min(maxe,dp[N-1][i]);
        }
        return maxe;
    }