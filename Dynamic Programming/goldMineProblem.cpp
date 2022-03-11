//https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions#
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int x,int y,int n,int m,vector<vector<int>> &M,vector<vector<int>> &dp)
    {
        if(x<0||y<0||x>=n||y>=m)
            return 0;
        if(dp[x][y]!=-1)
            return dp[x][y];
        return dp[x][y]=M[x][y]+max(solve(x,y+1,n,m,M,dp),max(solve(x-1,y+1,n,m,M,dp),solve(x+1,y+1,n,m,M,dp)));
        
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ok = M[0][0];
        int r = 0;

        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0;
        solve(r,0,n,m,M,dp);
        for(int j=0;j<n;j++)
        {
            ans=max(ans,solve(j,0,n,m,M,dp));
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends