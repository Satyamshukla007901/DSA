class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       int N = prices.size();
        // return f(0,1,2,N,prices);
        //memoisation
        // vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(3,-1)));
        // return f(0,1,2,N,prices,dp);
        //tabulation
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int i=N-1;i>=0;i--)
        {
            for(int b = 0;b<=1;b++)
            {
                for(int c = 1;c<=k;c++)
                {
                    if(b==1)
                    {
                        dp[i][b][c] = max(-prices[i]+dp[i+1][0][c],dp[i+1][1][c]);
                    }
                    else
                    {
                        dp[i][b][c] = max(prices[i]+dp[i+1][1][c-1],dp[i+1][0][c]);
                    }
                }
            }
        }
        return dp[0][1][k];

    }
};