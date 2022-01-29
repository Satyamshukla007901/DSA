//https://practice.geeksforgeeks.org/problems/queue-reversal/1
queue<int> rev(queue<int> q)
{
    int  N = q.size();stack<int> qq;
    for(int i=1;i<=N;i++)
    {
        int ok = q.front();
        q.pop();
        qq.push(ok);
    }
    for(int i=1;i<=N;i++)
    {
        q.push(qq.top());
        qq.pop();
    }
    return q;
    
    // add code here.
}