//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/
class Solution {
public:
    int f(int ind,int buy,int N,vector<int> &p,vector<vector<int>> &dp)
    {
        if(ind>=N)
                return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
        {
            return dp[ind][buy] = max(-p[ind]+f(ind+1,0,N,p,dp),f(ind+1,1,N,p,dp));
        }
        return dp[ind][buy] = max(p[ind]+f(ind+2,1,N,p,dp),f(ind+1,0,N,p,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> vp(prices.size(),vector<int>(2,-1));
            return f(0,1,prices.size(),prices,vp);   
    }
};