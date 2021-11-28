#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    ll T;
    cin>>T;
    while(T-->0)
    {
        ll N,K;
        cin>>N>>K;
        if(K%2==0)
        {
            cout<<(N-K)*2 + K-2<<endl;
        }
        else
            cout<<(N-K)*2 + K-1<<endl;
    }
    return 0;
}