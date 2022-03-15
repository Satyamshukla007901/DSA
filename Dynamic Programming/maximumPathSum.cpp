https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int x,int y,int N,vector<vector<int>> &m,vector<vector<int>> &dp)
    {
        if(x<0||y<0||x>N-1||y>N-1)
            return 0;
        else if(x==0&&y<N)
        {
            return m[0][y];
        }
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        return dp[x][y] = m[x][y]+max(solve(x-1,y-1,N,m,dp),max(solve(x-1,y,N,m,dp),solve(x-1,y+1,N,m,dp)));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        int ans = INT_MIN;
        for(int i=0;i<N;i++)
        {
            ans = max(ans,solve(N-1,i,N,Matrix,dp));
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
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends