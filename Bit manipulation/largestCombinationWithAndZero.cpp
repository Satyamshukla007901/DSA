//https://leetcode.com/contest/weekly-contest-293/problems/largest-combination-with-bitwise-and-greater-than-zero/
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> ok(32,0);
        for(auto &value:candidates)
        {
            for(int i=0;i<32;i++)
            {
                if((value>>i)&1)
                    ok[i]++;
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<32;i++)
        {
            ans = max(ans,ok[i]);
        }
        return ans;
    }
};