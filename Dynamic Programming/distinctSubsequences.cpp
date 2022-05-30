//https://leetcode.com/problems/distinct-subsequences/submissions/
class Solution {
public:
    int f(int i,int j,string s,string t,vector<vector<int>> &dp)
    {
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]) return dp[i][j] = f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        return dp[i][j] = f(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        // return f(s.length(),t.length(),s,t);
        //memoisation
        // vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,-1));
        // return f(s.length(),t.length(),s,t,dp);
//         tabulation
    vector<vector<double>> dp(s.length()+1,vector<double>(t.length()+1,0));
        
        for(int i=0;i<=s.length();i++) dp[i][0]=1;
        
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=t.length();j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[s.length()][t.length()];
        
    }
};