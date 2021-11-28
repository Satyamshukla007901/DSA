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
long long unsigned int power(long long unsigned int x,long long unsigned int y,long long unsigned int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
void solve()
{
    ll N,K;
    cin>>N>>K;
    vector<ll> vp;
    for(int i=0;i<N;i++)
    {
        ll x;
        cin>>x;
        vp.push_back(x);
    }
    int sum=vp[0];int count=1;int maxi;
    if(K==1)
         maxi=vp[0];
    else
        maxi=INT_MAX;
    int idx=0;int ans=1;
    for(int i=1;i<N;i++)
    {
        sum+=vp[i];
        count++;
        if(count==K+1)
        {
            count=0;
            sum-=vp[idx];
            idx++;
        }
        if(sum<maxi)
        {
            maxi=sum;
            ans=idx+1;
        }

    }
    cout<<ans<<" "<<maxi<<endl;
}
int main() {
    //  ll T;
    //  cin>>T;
    //  while(T-->0)
    //  {
          solve();
    //  }
	// your code goes here
	return 0;
}
