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
    long long T;
    cin>>T;
    while(T-->0)
    {
        long long A,B;
        cin>>A>>B;
        if((B-A)%2==0&&(B-A)!=0)
            cout<<((B-A)/2)+1<<endl;
        else if((B-A)==0)
            cout<<0<<endl;
        else
            cout<<(int)(ceil((B-A)/2.0))<<endl;
    }
	// your code goes here
	return 0;
}
