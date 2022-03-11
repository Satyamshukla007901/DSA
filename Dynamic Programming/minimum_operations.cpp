//https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
  int solve(int n,vector<int> &dp)
  {
      if(n==0)
        return 0;
      if(dp[n]!=-1)
            return dp[n];
      if(n%2!=0)
      {
          return dp[n]=1+solve(n-1,dp);
      }
      else
          return dp[n]=1+solve(n/2,dp);
  }
    int minOperation(int n)
    {
        //greedy approach
        /*
        int cnt = 0;
        int a = 0;
        while(n>=1)
        {
            if(n&1)
            {
                n--;cnt++;
            }
            else
            {
                n=n/2;cnt++;
            }
        }
        return cnt;*/
        //dp approach
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        //code here.
        return solve(n,dp);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends