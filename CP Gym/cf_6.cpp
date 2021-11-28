#include <bits/stdc++.h>
using namespace std;
#define  ll long long
int32_t main()
{
    
    ll N;
    cin>>N;
    vector<long long> v;
    for(int i=0;i<N;i++)
    {
        ll X;
        cin>>X;
        v.push_back(X);
    }
    ll mx = *max_element(v.begin(),v.end());
    ll mn = *min_element(v.begin(),v.end());
    ll cmx = count(v.begin(),v.end(),mx);
    ll cmn = count(v.begin(),v.end(),mn);
    cout<<abs(mx-mn)<<" ";
    if(mx!=mn)
    // ll cmx = count(v.begin(),v.end(),mx);
    // ll cmn = count(v.begin(),v.end(),mn);
        cout<<cmx*cmn<<endl;
    else
        cout<<(cmx*(cmx-1))/2<<endl;
}