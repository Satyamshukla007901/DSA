#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int32_t main()
{
    ll N,K;
    cin>>N>>K;
    vector<ll> vp;
    for(int i=0;i<N;i++)
    {
        ll X;
        cin>>X;
        vp.push_back(X);
    }

    int left=0;
    int right=0;int ans=1;ll sum=0,mini=INT_MAX;
    for(int i=0;i<N;i++)
    {
        right=i;
        sum+=vp[i];
        if((right-left+1)>K)
        {
            sum-=vp[left];
            left++;
        }
        if((right-left+1)==K)
        {
            if(sum<mini)
            {
                mini=sum;
                ans=left+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}