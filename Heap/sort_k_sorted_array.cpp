vector<int> sortksorted(vector<int> &vp,int n,int k)
{
    priority_queue<int,vector<int>,greater<int>> minh;
    vector<int> ans(n);
    int idx = 0;
    for(int i=0;i<n;i++)
    {
        pq.push(vp[i]);
        if(pq.size()>k)
        {
            ans[idx++]=pq.top();
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        ans[idx++]=pq.top();
        pq.pop();
    }
    return ans;
}