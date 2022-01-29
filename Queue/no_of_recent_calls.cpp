//https://leetcode.com/problems/number-of-recent-calls/submissions/
queue<int> q;
RecentCounter()
{
}

int ping(int t)
{

    q.push(t);
    while (!q.empty() && q.front() < (t - 3000))
        q.pop();
    return q.size();
    /*
        int l = t-3000;
        int r = t;
        queue<int> temp = q;int cnt = 0;
        while(!temp.empty())
        {
            if(temp.front()>=l&&temp.front()<=r)
            {
                cnt++;
            }
            temp.pop();
        }
        return cnt;
        */
}