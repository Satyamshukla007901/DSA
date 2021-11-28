#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    long long N,T;
    cin>>N>>T;
    vector<long long> vp;
    for(long long i=0 ;i<N;i++)
    {
        long long X;
        cin>>X;
        vp.push_back(X);
    }
    long long pt1,pt2;
    pt1=vp[0];
    pt2=pt1;
    long long cnt=1;int a=1;long long ans=0;
    int mn = *min_element(vp.begin(),vp.end());
    if(mn>T)
        cnt=0;
    for(long long i=1;i<N;i++)
    {
        pt2+=vp[i];
        cnt++;
        if(pt2>T)
        {
            pt2-=pt1;
            cnt--;
            pt1=vp[a];
            a++;
        }
        ans=max(ans,cnt);

    }
    cout<<max(ans,cnt)<<endl;
    return 0;
}