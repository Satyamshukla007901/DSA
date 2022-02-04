//https://www.geeksforgeeks.org/print-sums-subsets-given-set/

vector<int> kclosesttoorigin(vector<vector<int>> vp,int k)
{
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=0;i<vp.size();i++)
    {
        pq.push({vp[i][0]*vp[i][0]+vp[i][1]*vp[i][1],{vp[i][0],vp[i][1]}});
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while(!pq.empty())
    {
        vector<int> t(2);
        t[0]=pq.top().second.first;
        t[1]=pq.top().second.second;
        ans.push_back(t);
        pq.pop();
    }
    return ans;
}