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
        double X,Y;
        cin>>X>>Y;
        double ans = (max(6-(X+Y),0.0))/6.0;
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
	// your code goes here
	return 0;
}
