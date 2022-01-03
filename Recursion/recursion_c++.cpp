#include <bits/stdc++.h>
//print 1 to N by recursion
void printN(int N)
{
    if(N==0)
        return ;
    printN(N-1);
    cout<<N<<" ";
}
//Sort an Array
void insert(vector<int> &vp,int ok)
{
    if(vp.size()==0||vp[vp.size()-1]<=ok)
    {
        vp.push_back(ok);
        return;
    }
    int val = vp[vp.size()-1];
    vp.pop_back();
    insert(vp,ok);
    vp.push_back(val);
}
void sort(vector<int> &vp)
{
    if(vp.size()==1)
        return;
    int temp = v[v.size()-1];
    v.pop_back();
    sort(vp);
    insert(v,temp);
}
//Sort a stack usign recursion
//Geeks for geesks me hai
void sInsert(stack<int> &st,int item)
{
    if(st.size()==0||st.top()<=item)
    {
        st.push(item);
        return;
    }
    int ok = st.top();
    st.pop();
    sInsert(st,item);
    st.push(ok);
}
void SortedStack :: sort()
{
    if(s.empty())
        return;
    int ok = s.top();
    s.pop();
    sort();
    sInsert(s,ok);
   //Your code here
}