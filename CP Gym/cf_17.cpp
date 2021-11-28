#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long N,K;
    cin>>N>>K;
    if(K==0)
    {
        for(int i=1;i<=N;i++)
            cout<<i<<" ";
        cout<<endl;
    }
    else
    {
        for(int j=1;j<=N-K-1;j++)
            cout<<j<<" ";
        int i;
        for(i=N;i>=N-K;i--)
            cout<<i<<" ";
        // for(int j=1;j<=i;j++)
        //     cout<<j<<" ";
        // cout<<endl;
    }
}