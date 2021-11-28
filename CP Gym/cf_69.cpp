#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    long long T;
    cin>>T;
    while(T-->0)
    {
        long long X,Y;
        cin>>X>>Y;
        long long ans=0;
        while(X!=Y)
        {
            if(X>Y)
            {
                X-=1;
            }
            else
            {
                X+=2;
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}