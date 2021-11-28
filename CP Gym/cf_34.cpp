#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin>>n;
    int ce=0,co=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
        ce += (x%2==0);
        co += (x%2!=0);
    }

    if(sum%2!=0)
        cout<<co<<endl;
    else
    {
        if(co%2!=0)
            cout<<ce+co<<endl;
        else
            cout<<ce<<endl;
    }
}