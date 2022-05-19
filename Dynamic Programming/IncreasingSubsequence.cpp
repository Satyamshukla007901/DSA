//https://practice.geeksforgeeks.org/problems/increasing-sub-sequence1712/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
int longestSubsequence(int n, string str)
{
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (str[i] > str[j])
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
    int maxLength(string S)
    {
        return longestSubsequence(S.length(),S);
        // code here
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}  // } Driver Code Ends