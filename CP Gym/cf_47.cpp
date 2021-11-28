#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007
#define satyam ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fori(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define elif else if
const ll INF=1e17;
const ll NINF=(-1)*INF;
int main() {
    satyam;
    ll T;
    cin>>T;
    while(T-->0)
    {
        ll X;
        cin>>X;
        if(X==0)
            cout<<1<<endl;
        else if(X==1)
            cout<<2<<endl;
        else if(X==2)
            cout<<2<<endl;
        else
        {
             ll temp=1;
             while(temp<=X)
             {
                 temp*=2;
             }
             temp/=2;
             if(X == temp)
                cout<<X<<endl;
             else if(X == temp*2 -1)
             {
                 cout<<X+1<<endl;
             }
             else
             {
                 cout<<temp<<endl;
             }


        }
    }
	// your code goes here
	return 0;
}
