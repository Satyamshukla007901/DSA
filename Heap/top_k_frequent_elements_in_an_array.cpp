//https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1/#
    vector<int> topK(vector<int>& nums, int k) {
        
        map<int,int> mp;
        for(auto &value:nums)
        {
            mp[value]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &value:mp)
        {
            pq.push({value.second,value.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // Code here
    }

//my approach
    struct cmp
    {
            bool operator()(pair<int,int> p1,pair<int,int> p2)
            {
                if(p1.first==p2.first)
                {
                    return p1.second>p2.second;
                }
                return p1.first>p2.first;
            }
    };
    vector<int> topK(vector<int>& nums, int k) {
        
        map<int,int> mp;
        for(auto &value:nums)
        {
            mp[value]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(auto &value:mp)
        {
            pq.push({value.second,value.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        // Code here
    }