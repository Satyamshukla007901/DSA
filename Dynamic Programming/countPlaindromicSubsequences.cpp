//https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1/?page=1&difficulty[]=-1&difficulty[]=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int solve(int i,int j,string str,vector<vector<long long int>> &dp)
    {
        if(i==j)
        {
            return 1;
        }
        else if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str[i]==str[j])
        {
            return dp[i][j] = (1+solve(i+1,j,str,dp)%1000000007+solve(i,j-1,str,dp)%1000000007)%1000000007;
        }
        return dp[i][j] = (solve(i+1,j,str,dp)%1000000007+solve(i,j-1,str,dp)%1000000007-solve(i+1,j-1,str,dp)%1000000007)%1000000007;
    }
    long long int  countPS(string str)
    {
        vector<vector<long long int>> dp(str.length(),vector<long long int>(str.length(),0));
        // return solve(0,str.length()-1,str,dp)%1000000007;
   
        int N = str.length();
        for(int g = 0;g<N;g++)
        {
            for(int i=0,j=g;j<N;i++,j++)
            {
                if(g==0)
                {
                    dp[i][j]=1;
                }
                else if(g==1)
                {
                    dp[i][j] = str[i]==str[j]?3:2;
                }
                else
                {
                    if(str[i]==str[j])
                    {
                        dp[i][j] = (dp[i][j-1]%1000000007+dp[i+1][j]%1000000007+1)%1000000007;
                    }
                    else
                    {
                        dp[i][j] = (dp[i][j-1]%1000000007+dp[i+1][j]%1000000007-dp[i+1][j-1]+1000000007)%1000000007;
                    }
                }
                
            }
            
        }
        return dp[0][N-1]%1000000007;
       //Your code here
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends