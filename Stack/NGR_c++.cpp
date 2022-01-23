//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/
//Next Greater Element
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans(n);
    ans[n - 1] = -1;
    stack<long long> st;
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (!st.empty() && st.top() < arr[i])
        {
            while (!st.empty() && st.top() < arr[i])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
    // Your code here
}

//Next Greater Eleemnt to the left
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans(n);
    ans[0] = -1;
    stack<long long> st;
    st.push(arr[0]);
    for (int i = 1; i <n; i++)
    {
        if (!st.empty() && st.top() < arr[i])
        {
            while (!st.empty() && st.top() < arr[i])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
    // Your code here
}