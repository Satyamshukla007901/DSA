//https://leetcode.com/problems/minimum-time-to-complete-trips/submissions/
class Solution {
public:
    bool isPossible(vector<int> &time,int totalTrips,long long mid)
    {
        int trip = 0;
        for(auto &value:time)
        {
            if(value>mid)
            {
                break;
            }
            if(trip>=totalTrips)
            {
                return true;
            }
            trip+=(mid/value);
            
        }
        if(trip>=totalTrips)
                return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
       
        long long sum = 0;
        sort(time.begin(),time.end());
        for(auto &value:time)
                sum+=value;
        long long l = time[0];
        long long h = l*totalTrips;long long ans = h;
       
        while(l<=h)
        {
            long long mid = l+(h-l)/2;
            if(isPossible(time,totalTrips,mid))
            {
                ans=min(mid,ans);
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};