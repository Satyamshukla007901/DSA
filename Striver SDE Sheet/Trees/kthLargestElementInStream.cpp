//https://leetcode.com/problems/kth-largest-element-in-a-stream/editorial/
//TC->O(NlogK+MlogK)
//Sc->O(K)
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;int i =-1;
    KthLargest(int k, vector<int>& nums) {
        i=k;
        for(auto &value:nums)
        {
            pq.push(value);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>i)
                pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */