

#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long t;
    cin>>t;
    while(t-->0)
    {
        long long N;
        cin>>N;
        vector<long long> v(N);
        for(long long i=0;i<N;i++)
        {
            cin>>v[i];
        }
        long long ans = 1e9;
        for(long long i=0;i<N;i++)
        {
            for(long long j=i;j<N;j++)
            {
                for(long long k=0;k<=j-i;k++)
                {
                    v[i+k] = (v[i+k]&v[j-k]);
                }
                long long x = *max_element(v.begin(),v.end());
                ans = min(ans,x);
            }
        }
        cout<<ans<<endl;
    }
}