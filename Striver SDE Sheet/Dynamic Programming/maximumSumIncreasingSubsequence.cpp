//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
Recursive 

//User function Template for Java

class Solution
{
	public int maxSumIS(int arr[], int n)  
	{  
	   return func(arr,n,0,-1);
	}  
	
	private int func(int[] arr,int n,int index,int prev){
	   
	    if(index==n) return 0;
	    
	    int take=0;
	    int notTake=func(arr,n,index+1,prev);
	    if(prev==-1 || prev<arr[index]){
	        take=arr[index]+func(arr,n,index+1,arr[index]);
	    }
	    return Math.max(notTake,take);
	}
}
 

MEMOIZATION 

//User function Template for Java

class Solution
{
	public int maxSumIS(int arr[], int n)  
	{  
	    int[][] dp=new int[n+1][n+1];
        for(int[] rows:dp){
            Arrays.fill(rows,-1);
        }
	   return func(arr,n,0,-1,dp);
	}  
	
	private int func(int[] arr,int n,int index,int prev,int[][] dp){
	   
	    if(index>=n) return 0;
	    if(dp[index][prev+1]!=-1) return dp[index][prev+1];
	    int take=0;
	    int notTake=func(arr,n,index+1,prev,dp);
	    if(prev==-1 || arr[prev]<arr[index]){
	        take=arr[index]+func(arr,n,index+1,index,dp);
	    }
	    return dp[index][prev+1]=Math.max(notTake,take);
	}
}
TABULATION:

class Solution{
public:
	int maxSumIS(int v[], int n)  
	{
	    vector<int> dp(n, 1);
        
        int maxi = *max_element(v, v+n);
        
        for(int i=0; i<n; ++i) {
            dp[i] = v[i];
            for(int prev=0; prev<i; ++prev) {
                if(v[i] > v[prev] && (v[i]+dp[prev] > dp[i])) {
                    dp[i] = v[i]+dp[prev];
                }
            }
            maxi = max(dp[i], maxi);                
        }
        
        return maxi;
	}  
}; 