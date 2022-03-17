https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/?page=1&difficulty[]=-1&difficulty[]=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
long long int count(int S[], int m, int n)
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
    long long countWays(int m)
    {
        int arr[2] = {1,2};
        return count(arr,2,m);
        // your code here
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends