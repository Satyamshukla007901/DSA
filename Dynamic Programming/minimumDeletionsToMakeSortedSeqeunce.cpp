//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence3248/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
int longestSubsequence(int n, int a[])
{
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                if (dp[j] > max)
                    max = dp[j];
            }
        }
        dp[i] = max + 1;
    }
    return *max_element(dp.begin(), dp.end());

    // your code here
}
	int minDeletions(int arr[], int n) 
	{ 
	    return n-longestSubsequence(n,arr);
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

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends