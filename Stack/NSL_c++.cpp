//Smallest number on left
//https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1/
vector<int> leftSmaller(int n, int a[])
{
    vector<int> ans;
    ans.push_back(-1);
    stack<int> st;
    st.push(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (!st.empty() && st.top() >= a[i])
        {
            while (!st.empty() && st.top() >= a[i])
                st.pop();
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
        }
        else if (st.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(st.top());
        }
        st.push(a[i]);
    }
    return ans;
    // code here
}