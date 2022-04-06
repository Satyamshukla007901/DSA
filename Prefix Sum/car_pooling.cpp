//https://leetcode.com/problems/car-pooling
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> ok(1001,0);
        for(auto &value:trips)
        {
            for(int i=value[1];i<value[2];i++)
            {
                ok[i]+=value[0];
            }
        }
        for(auto &value:ok)
        {
            if(value>capacity)
            {
                return false;
            }
        }
        return true;
    }
};