//https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int ind,int n,int arr[],int dp[])
    {
        if(ind>=n)
        {
            return 0;
        }
        if(dp[ind]!=-1)
            return dp[ind];
        
        int l = arr[ind]+solve(ind+2,n,arr,dp);
        
        int r = solve(ind+1,n,arr,dp);
        dp[ind] = max(l,r);
        return dp[ind];
    }
    int FindMaxSum(int arr[], int n)
    {
        int maxe = INT_MIN;
        int dp[n];
        memset(dp,-1,sizeof(dp));
        
        return solve(0,n,arr,dp);
        // Your code here
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends

//top down
    int FindMaxSum(int arr[], int n)
    {
        int dp[n];
        dp[0]=arr[0];
        dp[1] = max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[n-1];
        // Your code here
    }

//space optimised
    int FindMaxSum(int arr[], int n)
    {
        if(n==1)
            return arr[0];
        int prev1,prev2;
        prev1=arr[0];
        prev2 = max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
        {
            int curr = max(prev2,prev1+arr[i]);
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
        // Your code here
    }