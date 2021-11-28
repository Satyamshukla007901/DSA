#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long T;
    cin>>T;
    while(T-->0)
    {
        long long xa,ya,xb,yb,xc,yc;
        cin>>xa>>ya;
        cin>>xb>>yb;
        cin>>xc>>yc;
        if((xb==xa&&yb==yc)||(xb==xc&&yb==ya))
            cout<<"YES"<<endl;
        else if(xa==xc&&xa==xb)
            cout<<"YES"<<endl;
        else if(ya==yc&&ya==yb)
            cout<<"YES"<<endl;
        else if(xa==xc&&ya==yc)
        {
            if((xa==xb||ya==yb))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if(xa==xb&&ya==yb)
        {
            cout<<"YES"<<endl;
        }
        else if(xa==ya&&xb==yb&&xc==yc)
            cout<<"NO"<<endl;
        else
            cout<<"NO"<<endl;
    }
}