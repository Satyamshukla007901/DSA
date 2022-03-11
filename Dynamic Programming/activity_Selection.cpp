//The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of the previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({end[i],start[i]});
        }
        sort(vp.begin(),vp.end());
        int ok = 1;
        int p = 0;
        for(int i=1;i<n;i++)
        {
            if(vp[i].second>vp[p].first)
            {
                ok++;
                p=i;
            }
        }
        return ok;
        
        // Your code here
    }