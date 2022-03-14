//https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1/?page=2&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
//basically approach is if the last character mathches then we can either take it or leave it but if last character does not matcghes so we will definately leave it

memoisation approach

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(string s1,int n,string s2,int m,vector<vector<int>> &dp)
    {
        if(n==0&&m==0)
            return 1;
        if(n==0)
        {
            return 0;
        }
        else if(m==0)
        {
            return 1;
        }
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m]=solve(s1,n-1,s2,m-1,dp)+solve(s1,n-1,s2,m,dp);
        }
        else
            return dp[n][m]=solve(s1,n-1,s2,m,dp);
    }
    int countWays(string S1, string S2){
        vector<vector<int>> dp(S1.length()+1,vector<int>(S2.length()+1,-1));
        return solve(S1,S1.length(),S2,S2.length(),dp);
        // code here
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends


    int countWays(string S1, string S2){
        vector<vector<int>> dp(S1.length()+1,vector<int>(S2.length()+1,-1));
        for(int i=0;i<=S2.length();i++)
            dp[0][i]=0;
        for(int i=0;i<=S1.length();i++)
            dp[i][0]=1;
        dp[0][0]=1;
        for(int i=1;i<=S1.length();i++)
        {
            for(int j=1;j<=S2.length();j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[S1.length()][S2.length()];
        // code here
    }