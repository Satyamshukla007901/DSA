//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/submissions/
class Solution {
public:
    int f(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int ind = i;ind<=j;ind++)
        {
            int cost = cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        // vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        // return f(1,c,cuts,dp);
        //tabulation
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        for(int i=c;i>=1;i--)
        {
            for(int j=i;j<=c;j++)
            {
                // if(i>j) continue;
                int mini = 1e9;
                for(int ind = i;ind<=j;ind++)
                {
                    
                    int cost = cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
            
        }
        return dp[1][c];
        
    }
};