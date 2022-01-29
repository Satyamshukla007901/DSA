//https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#
queue<int> modifyQueue(queue<int> q, int k)
{
    int n = q.size();
    stack<int> st;
    int i = 0;
    while (i < k)
    {
        st.push(q.front());
        q.pop();
        i++;
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    i = 0;
    while (i < (n - k))
    {
        int a = q.front();
        q.pop();
        q.push(a);
        i++;
    }
    return q;
    // add code here.
}