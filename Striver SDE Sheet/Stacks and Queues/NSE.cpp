//https://www.interviewbit.com/problems/nearest-smaller-element/
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans(A.size(),-1);
    stack<int> st;
    st.push(A[0]);
    for(int i=1;i<A.size();i++)
    {
        if(!st.empty() and st.top()>=A[i])
        {
            while(!st.empty() and st.top()>=A[i])   
                st.pop();
            if(st.empty())
            {
                ans[i] = -1;
                
            }
            else
                ans[i] = st.top();
         }
         else
            ans[i] = st.top();
        st.push(A[i]);
    }
    return ans;
}
