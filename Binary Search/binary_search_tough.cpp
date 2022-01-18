
//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/the-furious-five-69521576/
/*
Name : Satyam Shukla
*/
/*
to get x/y as an integer do this --> (x+y-1)/y
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define fasio                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fori(i, a, b) for (int i = a; i < b; i++)
#define endl "\n"
#define elif else if
const ll INF = 1e17;
const ll NINF = (-1) * INF;
#define LIMIT 1000000
long long i, j;
long long prime_flag[LIMIT];
void calculate_prime_flag()
{
    prime_flag[0] = prime_flag[1] = 1;
    for (i = 2; i < LIMIT; i++)
    {
        // to avoid overflow u can also set i*i<LIMIT
        if (prime_flag[i] == 0)
        {
            for (j = i * i; j < LIMIT; j += i)
            {
                prime_flag[j] = 1;
            }
        }
    }
    //0 -> prime
    //1 -> not prime
}
long long unsigned int power(long long unsigned int x, long long unsigned int y, long long unsigned int p)
{
    int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
bool isValid(ll N,ll X)
{
	ll cnt=0;
	while(X!=0)
	{
		cnt+=X/5;
		X=X/5;
		
	}
	if(cnt>=N)
		return true;
	return false;
}
void solve()
{
   ll N;
   cin>>N;
   ll s = 1;
   ll e = 1e18;ll ans = e;
   while(s<=e)
   {
	   ll mid = s + (e-s)/2;
	   if(isValid(N,mid))
	   {
		  e=mid-1;
		  ans=min(ans,mid);
	   }
	   else
	   {
		   s = mid+1;
	   }
   }
   cout<<ans<<endl;
}
int main()
{
    ll T;
    cin >> T;
    while (T-- > 0)
    {
        solve();
    }
    // your code goes here
    return 0;
}

///
//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/the-old-monk/
/*
Name : Satyam Shukla
*/
/*
to get x/y as an integer do this --> (x+y-1)/y
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define fasio                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fori(i, a, b) for (int i = a; i < b; i++)
#define endl "\n"
#define elif else if
const ll INF = 1e17;
const ll NINF = (-1) * INF;
#define LIMIT 1000000
long long i, j;
long long prime_flag[LIMIT];
void calculate_prime_flag()
{
    prime_flag[0] = prime_flag[1] = 1;
    for (i = 2; i < LIMIT; i++)
    {
        // to avoid overflow u can also set i*i<LIMIT
        if (prime_flag[i] == 0)
        {
            for (j = i * i; j < LIMIT; j += i)
            {
                prime_flag[j] = 1;
            }
        }
    }
    //0 -> prime
    //1 -> not prime
}
long long unsigned int power(long long unsigned int x, long long unsigned int y, long long unsigned int p)
{
    int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
void solve()
{
   ll N;
   cin>>N;
   vector<ll> a;
   vector<ll> b;
   for(int i=1;i<=N;i++)
   {
	   ll X;
	   cin>>X;
	   a.push_back(X);
   }
   for(int i=1;i<=N;i++)
   {
	   ll X;
	   cin>>X;
	   b.push_back(X);
   }
   int ans = 0;int maxe=0;
   for(int i=0;i<N;i++)
   {
	   int s = 0;ans=-1;
	   int e = N-1;
	   while(s<=e)
	   {
		   int mid = s + (e-s)/2;
			if(b[mid]>=a[i])
			{
				ans=mid;
				s=mid+1;
			}
			else
				e=mid-1;
	   }
		maxe=max(maxe,ans-i);
   }
   cout<<maxe<<endl;
}
int main()
{
    ll T;
    cin >> T;
    while (T-- > 0)
    {
        solve();
    }
    // your code goes here
    return 0;
}
