https://leetcode.com/problems/unique-paths
https://leetcode.com/problems/unique-paths-ii

PART 1 
class Solution {
public:
    long long int solve(int m,int n,vector<vector<long long>> &dp)
    {
        if(m==1&&n==1)
            return dp[m][n]=1;
        if(m<1||n<1)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        return dp[m][n]=(solve(m-1,n,dp)+solve(m,n-1,dp));
    }
    long long int numberOfPaths(int m, int n){
        
        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,0));
        
        dp[1][1]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1&&j==1)
                {    dp[i][j]=1;continue;}
                int left = 0,right = 0;
                if(i-1>=1)
                {
                    left = dp[i-1][j];
                }
                if(j-1>=1)
                    right = dp[i][j-1];
                dp[i][j]=left+right;
            }
        }
        return dp[m][n];
        // code here
    }
    int uniquePaths(int m, int n) {
        return numberOfPaths(m,n);
    }
};

PART2
class Solution {
public:
    int solve(int m,int n,vector<vector<int>> &dp,vector<vector<int>>& ob)
    {

        if(m>=1&&n>=1&&ob[m-1][n-1]==1)
                return 0;
        if(m==1&&n==1)
            return dp[m][n]=1;
        if(m<1||n<1)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        return dp[m][n]=(solve(m-1,n,dp,ob)+solve(m,n-1,dp,ob));
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,dp,ob);
    }
};