//https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/
vector<int> help_classmate(vector<int> arr, int n)
{
    vector<int> ans(n);
    ans[n - 1] = -1;
    stack<int> st;
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (!st.empty() && st.top() >= arr[i])
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
        }
        else if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
    // Your code goes here
}