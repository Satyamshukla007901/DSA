#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
   ll T;
   cin>>T;
   ll t=0;
   while(T-->0)
   {
       ll K;
       cin>>K;
       ll A[K];
       for(ll i=0;i<K;i++)
            cin>>A[i];
       ll pro = 1;
       sort(A,A+K);
        cout<<"Case "<<t+1<<": ";
        if(K==1)
            cout<<A[0]*A[0]<<endl;
        else
            cout<<A[0]*A[K-1]<<endl;
        t++;
   }
}