#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007
#define fasio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fori(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define elif else if
const ll INF=1e17;
const ll NINF=(-1)*INF;
int main() {
    int T;
    cin>>T;
    while(T-->0)
    {
        ll N;
        cin>>N;
        if(N==1)
            cout<<1<<endl;
        else
        {
             ll temp=1;
             while(temp<=N)
             {
                 temp*=2;
             }
             temp/=2;
             cout<<max(temp/2,N-temp+1)<<endl;
        }
    }
	// your code goes here
	return 0;
}
