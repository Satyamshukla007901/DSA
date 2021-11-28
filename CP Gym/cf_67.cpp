#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        long long A,B,C;
        cin>>A>>B>>C;
        if(A>max(B,C))
        {
            cout<<0<<" ";
        }
        else if(A<=max(B,C))
        {
            cout<<max(B,C)-A+1<<" ";
        }
        if(B>max(A,C))
        {
            cout<<0<<" ";
        }
        else if(B<=max(A,C))
        {
            cout<<max(A,C)-B+1<<" ";
        }
        if(C>max(B,A))
        {
            cout<<0<<endl;
        }
        else
            cout<<max(A,B)-C+1<<endl;
    }
    return 0;
}