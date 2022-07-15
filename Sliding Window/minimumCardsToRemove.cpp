//https://leetcode.com/contest/weekly-contest-186/problems/maximum-points-you-can-obtain-from-cards/
class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        long long sum = 0;
        for(auto &value:arr) sum+=value;
        int i = 0;
        int j = 0;
        long long curr = 0;
        long long ans = INT_MIN;
        int N = arr.size();
        if(k==N) return sum;
        while(j<N)
        {
            curr+=arr[j];
            if(j-i+1<N-k)
            {
                j++;
            }
            else
            {
                ans = max(ans,sum-curr);
                curr-=arr[i];
                i++;
                j++;
            }
        }
        return ans;
            
    }
};