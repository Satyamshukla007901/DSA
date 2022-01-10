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
//Subarray with 0 sum
//https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1/
bool subArrayExists(int arr[], int n)
{

    vector<int> prefix(n, 0);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    sort(prefix.begin(), prefix.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (prefix[i] == prefix[i + 1] || prefix[i] == 0)
        {
            return true;
        }
    }
    return false;
    //Your code here
}
//https://www.geeksforgeeks.org/find-prime-number-can-written-sum-consecutive-primes/
#define LIMIT 1000000
long long i, j;
long long prime_flag[LIMIT];
void calculate_prime_flag()
{
    prime_flag[0] = prime_flag[1] = 1;
    for (i = 2; i < LIMIT; i++)
    {
        // to avoid overflow u can also set i*i<LIMIT
        if (prime_flag[i] == 0)
        {
            for (j = i * i; j < LIMIT; j += i)
            {
                prime_flag[j] = 1;
            }
        }
    }
    //0 -> prime
    //1 -> not prime
}
int solve(int N)
{
    calculate_prime_flag();

    vector<int> primes;
    for (int i = 1; i <= 10000; i++)
    {
        if (prime_flag[i] == 0)
        {
            primes.push_back(i);
        }
    }
    vector<int> prefix(primes.size(), 0);
    prefix[0] = primes[0];
    for (int i = 1; i < primes.size(); i++)
    {
        prefix[i] = prefix[i - 1] + primes[i];
    }
    int max_l = INT_MIN;
    int ans = -1;
    for (int i = 0; primes[i] <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (prefix[i] - prefix[j] > N)
                break;

            int sum = prefix[i] - prefix[j];
            if (binary_search(primes.begin(), primes.end(), sum))
            {
                if (i - j + 1 > max_l)
                {
                    max_l = i - j + 1;
                    ans = sum;
                }
            }
        }
    }
    return ans;
}
//Maximum occcured integer
//https://www.geeksforgeeks.org/maximum-occurred-integer-n-ranges/
int maxOccured(int L[], int R[], int n, int maxx)
{
    int prefix[1000001];
    for (int i = 0; i < maxx; i++)
        prefix[i] = 0;
    for (int i = 0; i < n; i++)
    {
        prefix[L[i]]++;
        prefix[R[i] + 1]--;
    }
    for (int i = 1; i < maxx; i++)
    {
        prefix[i] += prefix[i - 1];
    }
    int maxe = INT_MIN;
    int ans = -1;
    for (int i = 0; i < maxx; i++)
    {
        if (prefix[i] > maxe)
        {
            ans = i;
        }
        maxe = max(maxe, prefix[i]);
    }
    return ans;
    // Your code here
}
int32_t main()
{
    return 0;
}