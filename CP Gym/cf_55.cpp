#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
       int N;
       cin>>N;
       vector<int> vp;
       for(int i=0;i<N;i++)
       {
           int x;
           cin>>x;
           vp.push_back(x);
       }
       sort(vp.begin(),vp.end());
       ll ans=0;
       for(int i=1;i<vp.size();i++)
       {
           ans=__gcd(ans,(ll)vp[i]-vp[i-1]);
       }
       if(ans==0)
            cout<<-1<<endl;
       else
            cout<<ans<<endl;
    }
    return 0;
}