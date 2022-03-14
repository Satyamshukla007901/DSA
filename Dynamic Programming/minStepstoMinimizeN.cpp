// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int N,vector<int> &dp)
	{
	    if(N==1)
	        return 0;
	    if(N<=0)
	        return INT_MAX;
	    if(dp[N]!=-1)
	        return dp[N];
	    int a = INT_MAX;
        int c = INT_MAX;
	    int b = INT_MAX;
	    if(N%2==0)
	    {
	        a=1+solve(N/2,dp);
	    }
	    if(N%3==0)
	    {
	        b=1+solve(N/3,dp);
	    }
	    c = 1+solve(N-1,dp);
	    
	    return dp[N]=min(min(a,b),c);
	}
	int minSteps(int N) 
	{ 
	    vector<int> dp(N+1,-1);
	    return  solve(N,dp);
	    
	    // Your code goes here
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends

  //TOP DOWN APPROACH
  	int minSteps(int N) 
	{ 
	    vector<int> dp(N+1,-1);
	    dp[1]=0;dp[0]=INT_MAX;
	    for(int i=2;i<=N;i++)
	    {
	        int a = INT_MAX,b=INT_MAX;
	        if(i%2==0)
	        {
	            a=dp[i/2]+1;
	        }
	        if(i%3==0)
	        {
	            b=dp[i/3]+1;
	        }
	        int c=1+dp[i-1];
	        dp[i]=min(min(a,b),c);
	    }
	    return dp[N];
	    
	    // Your code goes here
	} 