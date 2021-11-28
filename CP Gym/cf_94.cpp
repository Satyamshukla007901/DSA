#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int N;
        cin>>N;
        vector<long long> vp;
        for(int i=0;i<N;i++)
        {
            long long x;
            cin>>x;
            vp.push_back(x);
        }
        int count=0;long long mx=INT_MIN;
        for(int i=0;i<vp.size();i++)
        {
            if(vp[i]-i-1>mx)
            {
                mx=vp[i]-i-1;
            }
        }
        cout<<mx<<endl;

    }
    return 0;
}