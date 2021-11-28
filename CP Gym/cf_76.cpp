#include <bits/stdc++.h>
using namespace std;
#define satyam                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long

int32_t main()
{
    ll N,X,Y;
    cin>>N>>X>>Y;int req;
    double ans = (Y/100.0)*N;
    if(ans==(ll)ans)
        req=ans;
    else
        req = ans+1;
    // int req = ans+1;
    if(X>req)
        cout<<0<<endl;
    else
        cout<<abs(req-X)<<endl;
    return 0;
}