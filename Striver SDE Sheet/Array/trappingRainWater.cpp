//https://leetcode.com/problems/trapping-rain-water/submissions/
        vector<int> l(arr.size());
        l[0]=arr[0];
        for(int i=1;i<arr.size();i++)
            l[i] = max(arr[i],l[i-1]);
        vector<int> r(arr.size());
        r[arr.size()-1] = arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--)
        {
            r[i] = max(arr[i],r[i+1]);
        }
        long long ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            ans += abs(arr[i]-min(l[i],r[i]));
        }
        return ans;