#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long T;
    cin>>T;
    while(T-->0)
    {
        long long P;
        cin>>P;
        unordered_map<long long,long long> ump;
        for(long long i=2;i<P;i++)
        {
            if(ump[P%i])
            {
                cout<<ump[P%i]<<" "<<i;
                break;
            }
            ump[P%i]=i;
        }
        cout<<endl;
    }
}