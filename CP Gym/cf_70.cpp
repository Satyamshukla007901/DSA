#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    long long T;
    cin>>T;
    while(T-->0)
    {
        long long X,K;
        cin>>X>>K;
        cout<<X*2<<" "<<(X*K)*(X*K-1)<<endl;
    } 
    return 0;

}