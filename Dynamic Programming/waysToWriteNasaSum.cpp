//https://practice.geeksforgeeks.org/problems/ways-to-write-n-as-sum-1587115621/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of different ways in which n can be 
    //written as a sum of two or more positive integers.
long long int count(vector<int> &S, int m, int n)
{

    long long dp[m + 1][n + 1];
    for (int j = 1; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (S[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - S[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
    // code here.
}
    int countWays(int n)
    {
        // your code here
        vector<int> ok;
        for(int i=1;i<=n-1;i++)
            ok.push_back(i);
        return count(ok,ok.size(),n);
        
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.countWays(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends