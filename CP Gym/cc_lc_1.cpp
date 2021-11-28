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
        int G1,S1,B1,G2,S2,B2;
        cin>>G1>>S1>>B1>>G2>>S2>>B2;
        if((G1+S1+B1)>(G2+S2+B2))
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }
	return 0;
}
