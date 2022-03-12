//based on longest palindromic subsequence
https://practice.geeksforgeeks.org/problems/k-palindrome/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function*/
int lcs(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1];
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[x][y];
    // your code here
}
int longestPalindromeSubseq(string s)
{
    string str = s;
    reverse(s.begin(), s.end());
    return lcs(str.length(), s.length(), str, s);
}
bool is_k_palin(string s,int k)
{
    if(s.length()-longestPalindromeSubseq(s)<=k)
    {
        return true;
    }
    return false;
//Your code here
}