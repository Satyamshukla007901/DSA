#include <bits/stdc++.h>
using namespace std;
//Equal Sum
//https://practice.geeksforgeeks.org/problems/equal-sum0810/1/
string equilibrium(int *arr, int n)
{
    /* Space Complexity is O(2N)
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]+left[i]+arr[i];
        }
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i]+right[i+1]+arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(left[i]==right[i])
            {
                return "YES";
            }
        }
        return "NO";*/
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int left = 0;
    for (int i = 0; i < n; i++)
    {
        if (left == sum - left - arr[i])
        {
            return "YES";
        }
        left += arr[i];
    }
    return "NO";
    // code here
}
int32_t main()
{
    return 0;
}