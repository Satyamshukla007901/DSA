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
#define LIMIT 1000000
long long i, j;
long long prime_flag[LIMIT];
void calculate_prime_flag(){
    prime_flag[0] = prime_flag[1] = 1;
    for(i=2;i<LIMIT;i++){
        if (prime_flag[i]==0){
            for(j=i*i;j<LIMIT;j+=i){
                prime_flag[j] = 1;
            }
        }
    }
}
int main() {
    ll T;
    cin>>T;
    while(T-->0)
    {
        ll N,V;
        cin>>N>>V;
        ll mx = N*(N-1);
        mx/=2;
        ll req = N-1;
        ll mn;
        if(req<V)
            mn=req;
        else
        {
            ll ans = req-V;
            ans++;
            mn=V;
            ll ans1 = (ans*(ans+1))/2;
            ans1--;
            mn+=ans1;
        }
        cout<<mx<<" "<<mn<<endl;

    }
	// your code goes here
	return 0;
}
