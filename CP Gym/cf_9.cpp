#include <bits/stdc++.h>
using namespace std;
long long max(long long a,long long b)
{
    if(a>b)
        return a;
    return b;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        long long n;
        cin>>n;
        long long A[n];
        
        for(long long i=0;i<n;i++)
        {
            cin>>A[i];
            // s.insert(A[i]);
        }
        long long ans = A[0];
        for(long long i=1;i<n;i++)
            ans = max(ans,A[i-1]*A[i]);
        cout<<ans<<endl;
        // for(auto value:s)
        //     cout<<value<<" ";
        // cout<<endl;
        // if(s.size()==1)
        //     cout<<(*(s.begin()))*(*(s.begin()))<<endl;
        // else
        // {    auto it = s.begin();
        //     auto it2 = s.begin();
        //     ++it2;
        //     // cout<<*it<<" "<<*it2<<endl;
        //     cout<<(*it)*(*it2)<<endl;
        // }

    }
}