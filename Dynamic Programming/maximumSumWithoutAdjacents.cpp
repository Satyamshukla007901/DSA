//https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1/
	int solve(int ind,int arr[],int n,vector<int> &dp)
	{
	    if(ind==0)
	        return dp[0]=arr[0];
	    if(ind<0)
	        return 0;
	    if(dp[ind]!=-1)
	            return dp[ind];
	    return dp[ind] = max(arr[ind]+solve(ind-2,arr,n,dp),solve(ind-1,arr,n,dp));
	}
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,-1);
	    solve(n-1,arr,n,dp);
	    return dp[n-1];
	    // code here
	}