//https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       /*
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &value:nums)
        {
            pq.push(value);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();*/
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &value:nums)
        {
            pq.push(value);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
        
    }
};