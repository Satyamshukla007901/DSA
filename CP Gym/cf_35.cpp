#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        long long X,Y;
        cin>>X>>Y;
        long long sum = X*X + Y*Y;
        if(sum%2==0)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}