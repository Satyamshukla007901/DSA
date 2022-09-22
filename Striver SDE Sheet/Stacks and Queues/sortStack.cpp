#include <bits/stdc++.h>
using namespace std;
#define ll long long
void insert(stack<int> &st,int item)
{
    if(st.size()==0 or st.top()<=item)
    {
        st.push(item);
        return;
    }

    int val = st.top();
    st.pop();
    insert(st,item);
    st.push(val);
    return;
}
void sort(stack<int> &st)
{
    if(st.size()<=1)
    {
        return;
    }
    int item = st.top();
    st.pop();
    sort(st);
    insert(st,item);
    return;
} 

int32_t main()
{
    ll N;
    cin>>N;
    stack<int> st;
    for(int i=0;i<N;i++)
    {
        int X;
        cin>>X;
        st.push(X);
    }
    
    cout<<"Before Sorting : --- "<<endl;
    stack<int> temp = st;
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;cout<<"After Sorting : --- "<<endl;
    sort(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}