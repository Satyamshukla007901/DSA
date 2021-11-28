#include <bits/stdc++.h>
using namespace std;
#define satyam                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long
int32_t main()
{
    satyam;
    ll T;
    cin>>T;
    while(T-->0)
    {
        ll N;
        cin>>N;
        vector<ll> vp;
        for(int i=0;i<N;i++)
        {
            ll x;
            cin>>x;
            vp.push_back(x);
        }
        if(N==2)
            cout<<0<<endl;
        else if(N==3)
        {
            cout<<min(abs(vp[0]-vp[1]),min(abs(vp[1]-vp[2]),abs(vp[0]-vp[2])));
        }

    }
    return 0;
}