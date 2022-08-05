//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// approach is we have to accomodate max peoples in one room so we will try to end everymeeeting in shortest end time 
// so we will see which meeting will end at short time
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({start[i],end[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        int cnt = 1;
        int l = vp[0].first;
        int r = vp[0].second;
        for(int i=1;i<n;i++)
        {
            if(vp[i].first>r)
            {
                l=vp[i].first;
                r=vp[i].second;
                cnt++;
            }
            
        }
        return cnt;
        // Your code here
    }