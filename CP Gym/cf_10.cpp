#include <bits/stdc++.h>
using namespace std;
long long max(long a,long b)
{
    if(a>b)
        return a;
    return b;
}
int32_t main()
{
    long long t;
    cin>>t;
    while(t-->0)
    {
        long long n,k;
        cin>>n>>k;
        long long A[n];
        for(long long i=0;i<n;i++)
            cin>>A[i];
        long long ans = 1*2  - k*(A[0]|A[1]);
        for(long long i=1;i<n;i++)
        {
            ans = max(ans,(i+1)*i - k*(A[i-1]|A[i]));
        }
        // ans = max(ans,1*n - k*(A[0]*A[n-1]));
        cout<<ans<<endl;
    }
}