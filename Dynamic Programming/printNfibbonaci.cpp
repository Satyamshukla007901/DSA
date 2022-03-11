//https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    long long solve(int n,vector<long long> &dp)
    {
        if(n==1||n==2)
            return dp[n]=1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    vector<long long> printFibb(int n) 
    {
        vector<long long> dp(n+1,-1);
        dp[1]=1;
        dp[2]=1;
        solve(n,dp);
        vector<long long> ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(dp[i]);
        }
        return ans;
        //code here
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
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends