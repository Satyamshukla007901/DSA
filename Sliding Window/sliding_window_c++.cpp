#include <bits/stdc++.h>
using namespace std;
//Max Sum Subarray of Size K
//https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
int maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    /*
        int prefix[N];
        prefix[0]=Arr[0];
        for(int i=1;i<N;i++)
        {
            prefix[i]=prefix[i-1]+Arr[i];
        }
        int i = 0;int maxe = 0;
        for(int j=1;j<N;j++)
        {
            if(j-i+1>K)
            {
                i++;
            }
            if(j-i+1==K)
            {
                if(i-1<0)
                {
                    maxe = max(maxe,prefix[j]);
                }
                else
                    maxe = max(maxe,prefix[j]-prefix[i-1]);
                
            }
        }
        return maxe;*/
    /*Sliding Window Concept*/
    int i = 0;
    int j = 0;
    int sum = 0;
    int max_sum = INT_MIN;
    while (j < Arr.size())
    {
        sum += Arr[j];
        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            max_sum = max(max_sum, sum);
            sum -= Arr[i];
            i++;
            j++;
        }
    }
    return max_sum;
    // code here
}
//First negative integer in every window of size k
//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
//My approach
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    vector<long long> ans;
    int i = 0;
    int j = 0;
    priority_queue<int, vector<int>, greater<int>> idx;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 0)
        {
            idx.push(i);
            break;
        }
    }
    while (j < N)
    {
        if (A[j] < 0)
        {
            idx.push(j);
        }
        if (j - i + 1 == K)
        {
            if (idx.empty())
                ans.push_back(0);
            else if (idx.top() >= i && idx.top() <= j)
            {
                ans.push_back(A[idx.top()]);
            }
            else
            {
                while ((!idx.empty()) && (!(idx.top() >= i && idx.top() <= j)))
                {
                    idx.pop();
                }
                if (idx.empty())
                {
                    ans.push_back(0);
                }
                else
                {
                    ans.push_back(A[idx.top()]);
                }
            }

            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
int32_t main()
{
    return 0;
}