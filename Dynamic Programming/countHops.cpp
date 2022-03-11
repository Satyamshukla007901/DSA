//https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long solve(int n,vector<long long> &dp)
    {
        if(n==0||n==1||n==2)
        {
            return dp[n]=n;
        }
        else if(n==3)
        {
            return dp[n]=4;
        }
        if(dp[n]!=-1)
            return dp[n]%1000000007;
        return dp[n] = (solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp))%1000000007;
        // your code here
        
    }
    long long countWays(int n)
    {
        vector<long long> dp(n+1,-1);
        
        solve(n,dp);
        return dp[n];
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends