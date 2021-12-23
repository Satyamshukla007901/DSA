#include <bits/stdc++.h>
//KnapSack 0/1
//https : //practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
    // Your code here
}
//Subset Sum Probelm
//https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=4&query=category[]Dynamic%20Programmingpage4category[]Dynamic%20Programming
bool isSubsetSum(int N, int arr[], int sum)
{
    bool dp[N + 1][sum + 1];

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    // code here
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[N][sum];
}
//Equal Sum Partition Problem
//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return 0;
    sum /= 2;
    int dp[N + 1][sum + 1];
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > sum)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[N][sum];
    // code here
}
//Perfect Sum Problem
//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#

int perfectSum(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j] % 1000000007;
            else
                dp[i][j] = (dp[i - 1][j] % 1000000007) + (dp[i - 1][j - arr[i - 1]] % 1000000007) % 1000000007;
        }
    }
    return dp[n][sum] % 1000000007;

    // Your code goes here
}
//Minimum Sum Difference Partition
//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
bool dp[1005][1005];
bool subsetSum(int arr[], int n, int sum)
{

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[n][sum];
}
int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    vector<int> vp;
    subsetSum(arr, n, sum);
    subsetSum(arr, n, 0);
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i])
        {
            vp.push_back(i);
        }
    }
    int absmin = INT_MAX;
    int mid = -1;
    if (vp.size() % 2 == 0)
        mid = vp.size() - 1;
    else
        mid = vp.size();
    for (int i = 0; i <= mid; i++)
        absmin = min(absmin, abs(2 * vp[i] - sum));
    return absmin;
    // Your code goes here
}
//Count the number of given subsets having the given difference
int countSubset(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int ans = 0;
    subsetSum(arr, n, sum);
    subsetSum(arr, n, 0);
    vector<int> vp;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i])
        {
            vp.push_back(i);
        }
    }
    int mid = -1;
    if (vp.size() % 2 == 0)
        mid = vp.size() - 1;
    else
        mid = vp.size();
    for (int i = 0; i <= mid; i++)
    {
        if (abs(2 * vp[i] - sum) == diff)
        {
            ans++;
        }
    }
    return ans;
}
//another approach
int countSubset(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int ans = 0;
    ans = countSubset(arr, n, (sum + diff) / 2);
    cout << countSubset << endl;
}
//Target Sum
//https://leetcode.com/problems/target-sum/
int countSubset(vector<int> &vp, int sum)
{
    int n = vp.size();
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (vp[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - vp[i - 1]];
        }
    }
    return dp[n][sum];
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int s = accumulate(nums.begin(), nums.end(), 0) + target;
    if (accumulate(nums.begin(), nums.end(), 0) < target || s % 2 == 1)
        return 0;

    int sum = (s) / 2;
    sum = abs(sum);
    return countSubset(nums, sum);
}
//Unbounded KnapSack
//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
int knapSack(int N, int W, int val[], int wt[])
{
    int dp[N + 1][W + 1];
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][W];
    // code here
}
//Rod cutting problem
//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
int cutRod(int price[], int n)
{
    int length[n];
    for (int i = 0; i < n; i++)
        length[i] = i + 1;

    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (length[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][n];
    //code here
}
//Coin Problem Max Number of Ways
//https://practice.geeksforgeeks.org/problems/coin-change2448/1#
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
//Number of Coins
//https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#
int minCoins(int coins[], int M, int V)
{
    int dp[M + 1][V + 1];
    for (int j = 0; j <= V; j++)
        dp[0][j] = INT_MAX - 1;
    for (int i = 1; i <= M; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= V; j++)
    {
        if (j % coins[0] == 0)
            dp[1][j] = j / coins[0];
        else
            dp[1][j] = INT_MAX - 1;
    }

    for (int i = 2; i <= M; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[M][V] == INT_MAX - 1)
        return -1;

    return dp[M][V];
    // Your code goes here
}
//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
//Function to find the length of longest common subsequence in two strings.
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
//Longest Common Substring
//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
    // your code here
}
//Longest Common Subsequence Print
string printLcs(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
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
    ll i = n;
    ll j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
//Shortest Common Super Sequence
//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
int shortestCommonSupersequence(string X, string Y, int m, int n)
{
    //simply add the LCS and the remainign from the strings ==> ans = LCS+(m-LCS)+(n-LCS);
    return m + n - lcs(m, n, X, Y);
    //code here
}
//Minimum Number of Insertion Deletion
//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
int minOperations(string str1, string str2)
{
    //No. of Insertions : a.length()-lcs
    //No. of Deletions : b.length()-lcs;
    int n = str1.length();
    int m = str2.length();
    int ok = lcs(n, m, str1, str2);
    return n - ok + m - ok;
    // Your code goes here
}
//Longest Palindromic Subsequence
//https://leetcode.com/problems/longest-palindromic-subsequence/
int longestPalindromeSubseq(string s)
{
    string str = s;
    reverse(s.begin(), s.end());
    return lcs(str.length(), s.length(), str, s);
}
//Minimum Number os Deletions to make String palindrome
//https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1
int minimumNumberOfDeletions(string S)
{
    return S.length() - longestPalindromeSubseq(S);
    // code here
}
//Print Shortest Common SuperSequence
//https://leetcode.com/problems/shortest-common-supersequence/submissions/
string printshortestCommonSupersequence(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n;
    int j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += str1[i - 1];
                i--;
            }
            else
            {
                ans += str2[j - 1];

                j--;
            }
        }
    }
    while (i > 0)
    {
        ans += str1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += str2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
//Longest Repeating Subsequence
//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
int LongestRepeatingSubsequence(string str)
{
    int x = str.length(), y = str.length();
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
            if (str[i - 1] == str[j - 1] && i != j)
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
}
//Is Subseqeunce
//https://leetcode.com/problems/is-subsequence/
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
bool isSubsequence(string A, string B)
{
    if (lcs(A.length(), B.length(), A, B) == A.length())
        return 1;
    return 0;
    // code here
}
//Minimum Number of Insertion to make string palindrome
int countMin(string str)
{
    string t = str;
    reverse(t.begin(), t.end());
    return str.length() - lcs(str.length(), str.length(), str, t);
    //complete the function here
}
//Matrix Chain Multiplication Recursive Approach
//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
int solve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (tempans < ans)
            ans = tempans;
    }
    return ans;
}
int matrixMultiplication(int N, int arr[])
{
    int i = 1;
    int j = N - 1;
    return solve(arr, i, j);
    // code here
}