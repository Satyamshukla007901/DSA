#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int A[11];
        for(int i=1;i<=10;i++)
            cin>>A[i];
        int team1=0,team2=0;
        for(int i=1;i<=10;i+=2)
        {
            team1+=(A[i]==1);
        }
        for(int i=2;i<=10;i+=2)
        {
            team2+=(A[i]==1);
        }
        if(team1>team2)
            cout<<1<<endl;
        else if(team1<team2)
            cout<<2<<endl;
        else
            cout<<0<<endl;
    }
}