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