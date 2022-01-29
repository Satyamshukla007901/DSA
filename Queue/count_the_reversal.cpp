//https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1
int countRev (string s)
{
    int  n = s.length();
    if(n%2!=0)
        return -1;
    stack<char> st;int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='{')
            st.push(s[i]);
        else
        {
            if(st.empty()==false)
            {
                if(st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        
    }
    int o = 0;
    int c = 0;
    while(!st.empty())
    {
        if(st.top()=='{')
            o++;
        else
            c++;
        st.pop();
        
    }
    if(o%2==0&&c%2==0)
    {
        return o/2+c/2;
    }
    else if(o%2!=0&&c%2!=0)
    {
        return (o+c-2)/2+2;
    }
    // o even c odd or c even o odd case not possible
    // your code here
}