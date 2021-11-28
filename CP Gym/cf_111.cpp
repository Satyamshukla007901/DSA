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
    ll N;
    cin>>N;
    multimap<int,int,greater<int>> mp;
    multimap<int,int> ump;
    for(int i=0;i<N;i++)
    {
        int A,B;
        cin>>A>>B;
        mp.insert({B,A});
        ump.insert({A,B});
    } 
    vector<int> a;
    vector<int> b;
    vector<int> a1;
    vector<int> b1;
    for(auto &value:mp)
    {
        b.push_back(value.first);
        a.push_back(value.second);
    }
    for(auto &value:ump)
    {
        b1.push_back(value.second);
        a1.push_back(value.first);
    }
    bool flag=false,ans=false;
    for(int i=0;i<N-1;i++)
    {
        if(a[i]<a[i+1])
        {
            flag=true;
            break;
        }
    }
    for(int i=0;i<N-1;i++)
    {
        if(b1[i]>b1[i+1])
        {
            ans=true;
            break;
        }
    }
    if(N==1)
        cout<<"Poor Alex"<<endl;
    else if(flag||ans)
    {
        cout<<"Happy Alex"<<endl;
    }
    else
        cout<<"Poor Alex"<<endl;
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
