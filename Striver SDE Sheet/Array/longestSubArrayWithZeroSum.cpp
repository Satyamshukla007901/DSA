//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
    int maxLen(vector<int>&A, int n)
    {   
        map<int,vector<int>> mp;int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            mp[sum].push_back(i);
        }
        int ans = INT_MIN;
        for(auto &value:mp)
        {
            ans = max(ans,value.second[value.second.size()-1]-value.second[0]);
            if(value.first==0)
                ans=max(ans,value.second[value.second.size()-1]+1);
        }
        return ans;
        // Your code here
    }