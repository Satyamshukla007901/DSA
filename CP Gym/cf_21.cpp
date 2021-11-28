#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int N;
    cin>>N;
    int count=0;
    for(int i=1;i<N;i++)
    {
        for(int j=i;j*j<=((N*N)-(i*i));j++)
        {
            if(sqrt(i*i+j*j)*sqrt(i*i+j*j)==(i*i+j*j))
                count++;
        }
    }
    cout<<count<<endl;
}