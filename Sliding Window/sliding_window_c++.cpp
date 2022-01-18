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
//aditya verma
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    vector<long long> ans;
    int i = 0;
    int j = 0;
    list<long long> l;
    while (j < N)
    {
        if (A[j] < 0)
            l.push_back(A[j]);

        if (j - i + 1 < K)
            j++;
        else
        {
            if (l.size() == 0)
                ans.push_back(0);
            else
            {
                ans.push_back(l.front());
                if (A[i] == l.front())
                    l.pop_front();
            }
            j++;
            i++;
        }
    }

    return ans;
}
//Count Occurences ofAnagram
//https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
int search(string pat, string txt)
{

    int i = 0;
    int j = 0;
    int ans = 0;
    map<char, int> mp;
    for (auto &value : pat)
        mp[value]++;
    int N = txt.length();
    map<char, int> ump;
    while (j < N)
    {
        //Calculation
        ump[txt[j]]++;
        if (j - i + 1 < pat.length())
        {
            j++;
        }
        else if (j - i + 1 == pat.length())
        {
            //ans using calculation
            if (mp == ump)
            {
                ans++;
            }
            ump[txt[i]]--;
            if (ump[txt[i]] <= 0)
            {
                ump.erase(txt[i]);
            }
            j++;
            i++;
        }
        // for(auto &value:ump)
        //     cout<<value.first<<" "<<value.second<<endl;
        //cout<<endl;
    }
    return ans;
    // code here
}
//Verma ji Approach
int search(string pat, string txt)
{

    int i = 0;
    int j = 0;
    int ans = 0;
    unordered_map<char, int> mp;
    for (auto &value : pat)
        mp[value]++;
    int N = txt.length();
    int count = mp.size();
    // map<char,int> ump;
    while (j < N)
    {
        //Calculation
        if (mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]--;
            if (mp[txt[j]] == 0)
                count--;
        }
        // ump[txt[j]]++;
        if (j - i + 1 < pat.length())
        {
            j++;
        }
        else if (j - i + 1 == pat.length())
        {
            if (count == 0)
                ans++;
            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]++;
                if (mp[txt[i]] == 1)
                    count++;
            }
            //ans using calculation
            // if(mp==ump)
            // {
            //     ans++;
            // }
            // ump[txt[i]]--;
            // if(ump[txt[i]]<=0)
            // {
            //     ump.erase(txt[i]);
            // }
            j++;
            i++;
        }
    }
    return ans;
    // code here
}
//Sliding Window Maximum
//https://www.interviewbit.com/problems/sliding-window-maximum/#
#include <list>
vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
{
    if (B > A.size())
    {
        vector<int> ok;
        ok.push_back(*max_element(A.begin(), A.end()));
        return ok;
    }
    int i = 0;
    int j = 0;
    int N = A.size();
    vector<int> ok;
    list<int> st;

    while (j < N)
    {
        //Calculation
        while (st.size() > 0 && st.back() < A[j])
            st.pop_back();
        st.push_back(A[j]);
        if (j - i + 1 < B)
        {

            j++;
        }
        else if (j - i + 1 == B)
        {
            ok.push_back(st.front());
            if (A[i] == st.front())
                st.pop_front();
            j++;
            i++;
        }
    }
    return ok;
}
//Longest Subarray with sum K
//https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1/#
int lenOfLongSubarr(int A[], int N, int K)
{
    /* Only for positive Nummbers
        int i = 0;
        int j = 0;int sum = 0;
        int mx = 0;
        while(j<N)
        {
            sum+=A[j];
            if(sum<K)
                j++;
            else if(sum==K)
            {
                mx = max(j-i+1,mx);
                j++;
                
            }
            else if(sum>K)
            {
                while(sum>K)
                {
                    sum-=A[i];
                    i++;
                }
                j++;
            }
        }
        return mx;*/

    int sum = 0;
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum == K)
        {
            ans = max(ans, i + 1);
        }
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
        if (mp.find(sum - K) != mp.end())
            ans = max(ans, i - mp[sum - K]);
    }
    return ans;
    // Complete the function
}
int32_t main()
{
    return 0;
}
//Longest K unique character substring
//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
int longestKSubstr(string s, int k)
{
    unordered_map<char, int> mp;
    int i = 0;
    int j = 0;
    int N = s.length();
    int ans = -1;
    while (j < N)
    {
        //calculation
        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
    // your code here
}
//Longest substring with non repeating character
//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int N = s.length();
        int ans = 0;
        int j = 0;
        unordered_map<char, int> mp;
        while (j < N)
        {
            mp[s[j]]++;
            bool flag = false;
            if (mp[s[j]] == 2)
                flag = true;

            if (!flag)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (flag)
            {
                while (mp[s[i]] != 2)
                {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
//https://leetcode.com/problems/minimum-window-substring/submissions/
//minimum window substring
class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;int x=0;
        unordered_map<char,int> mp;
        for(auto &value:t)
                mp[value]++;
        int count = mp.size();int ans = INT_MAX;string ok="";
        while(j<s.length())
        {
           if(mp.find(s[j])!=mp.end())
           {
               mp[s[j]]--;
               if(mp[s[j]]==0)
                    count--;
           }
            if(count>0)
            {
                j++;
            }
            else if(count==0)
            {
                if(j-i+1<ans)
                {
                    ans=min(ans,j-i+1); 
                    x=i;
                    ok=s.substr(x,j-i+1);
                }
                        
                
                while(count==0)
                {
                    if(mp.find(s[i])==mp.end())
                    {
                        i++;
                        if(j-i+1<ans)
                        {
                            ans=min(ans,j-i+1);
                            x=i;
                            ok=s.substr(x,ans);
                        }
                    }
                    else
                    {
                        
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                        {
                            i++;
                            count++;
            
                        }
                        else
                        {
                            i++;
                            if(j-i+1<ans)
                            {
                                ans=min(ans,j-i+1); 
                                ok=s.substr(i,j-i+1);
                            }   
                        }
                    }
                }
                j++;
                
            }
        }

        return ok;
    }
};