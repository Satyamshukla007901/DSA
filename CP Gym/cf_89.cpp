#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    long long N;
    cin>>N;
    for(ll i=N;i>=1;i--)
    {
        for(ll j=1;j<=N;j++)
        {
            if(i==j&&j!=1&&j!=3)
                cout<<"Q";
            else
                cout<<".";
        }
        cout<<endl;
    }
}
int32_t main()
{
    long long T;
    cin>>T;
    while(T-->0)
    {
        solve();
    }
    return 0;
}