// https://leetcode.com/problems/corporate-flight-bookings
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ok(n,0);
        /* Naive Approach
        for(auto &value:bookings)
        {
            for(int i=value[0]-1;i<=value[1]-1;i++)
            {
                ok[i]+=value[2];
            }
        }*/
        vector<pair<int,int>> vp;
        for(auto &value:bookings)
        {
            vp.push_back({value[0],value[2]});
            vp.push_back({value[1]+1,-value[2]});
        }
        sort(vp.begin(),vp.end());
        for(auto &value:vp)
        {
            if(value.first<=n)
            {
                ok[value.first-1]+=value.second;
            }
        }
        for(auto &value:ok)
        {
            cout<<value<<" ";
        }
        cout<<endl;
        for(int i=1;i<n;i++)
        {
            ok[i]+=ok[i-1];
        }
        
        return ok;
    }
};