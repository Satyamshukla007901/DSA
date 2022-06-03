//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/
class Solution {
public:
    int f(int i,int b,vector<int> &p,int fee,vector<vector<int>> &dp)
    {
        if(i==p.size()) return 0;
        
        if(dp[i][b]!=-1) return dp[i][b];
        if(b)
        {
            return dp[i][b] = max(-p[i]+f(i+1,0,p,fee,dp),f(i+1,1,p,fee,dp));
        }
        return dp[i][b] = max(p[i]-fee+f(i+1,1,p,fee,dp),f(i+1,0,p,fee,dp));   
    }
    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return f(0,1,prices,fee,dp);
        //tabulation
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int b=0;b<=1;b++)
            {
                if(b)
                {
                    dp[i][b] = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else dp[i][b] = max(prices[i]-fee+dp[i+1][1],dp[i+1][0]); 
            }
        }
        return dp[0][1];
    }
};