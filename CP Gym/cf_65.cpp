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
    ll T;
    cin>>T;
    while(T-->0)
    {
        ll N;
        cin>>N;
        string S;
        cin>>S;
        bool ans = false;
        for(int i=0;i<N-1;i++)
        {
            if((S[i]=='L'&&S[i+1]=='L')||(S[i]=='R'&&S[i+1]=='R'))
            {
                ans = true;
                break;
            }
        }
        if(ans)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
	// your code goes here
	return 0;
}