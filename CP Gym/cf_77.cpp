#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    long long T;
    cin>>T;
    while(T-->0)
    {
        long long A,B,C;
        cin>>A>>B>>C;
        if(A==B&&B==C)
            cout<<0<<endl;
        else
        {
            cout<<abs(((A+2*B+3*C)/2)-(-((A+2*B+3*C)/2)+((A+2*B+3*C))))<<endl;
        }

    }
    return 0;
}