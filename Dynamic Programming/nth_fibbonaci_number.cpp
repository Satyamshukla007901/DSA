//https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions#
// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  long long solve(long long n,vector<long long> &dp)
  {
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n]%1000000007;
        return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%1000000007;
  }
    long long int nthFibonacci(long long int n){
        vector<long long int> dp(n+1,-1);
        solve(n,dp);
        return dp[n];
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends