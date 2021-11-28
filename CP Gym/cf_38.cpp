#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
       int X,Y,Z;
       cin>>X>>Y>>Z;
       if(X+(2*Z) >= Y)
         cout<<"YES"<<endl;
       else
         cout<<"NO"<<endl;
     
    }
    return 0;
}