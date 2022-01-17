//https://codeforces.com/contest/1562/problem/B
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
    ll K;
    cin >> K;
    string str;
    cin >> str;
    if (K == 1)
    {
        cout << K << endl;
        cout << str << endl;
    }
    else if (K == 3)
    {
        bool flag = false;
        for (int i = 0; i < K; i++)
        {
            if (prime_flag[str[i] - '0'] == 1)
            {

                cout << 1 << endl;
                cout << str[i] << endl;
                return;
            }
        }
        string ok = "";
        ok+=str[0];
        ok+=str[2];
        if(prime_flag[stoi(str.substr(0,2))]==1)
        {
            cout<<2<<endl;
            cout<<str[0]<<str[1]<<endl;
        }
        else if(prime_flag[stoi(str.substr(1,2))]==1)
        {
            cout<<2<<endl;
            cout<<str[1]<<str[2]<<endl;
        }
        else if(prime_flag[stoi(ok)]==1)
        {
            cout<<2<<endl;
            cout<<ok<<endl;
        }
        else
        {
            cout<<K<<endl;
            cout<<str<<endl;
        }
    }
    else
    {
        bool flag = false;unordered_map<char,int> mp;
        for (int i = 0; i < K; i++)
        {
            mp[str[i]]++;
            if (prime_flag[str[i] - '0'] == 1)
            {

                cout << 1 << endl;
                cout << str[i] << endl;
                return;
            }
        }
        for(auto &value:mp)
        {
            if(value.second>=2)
            {
                cout<<2<<endl;
                cout<<value.first<<value.first<<endl;return;
            }
        }
        
        for(int i=0;i<K-1;i++)
        {
            string ok = "";
            ok+=str[i];
            ok+=str[i+1];
            if(prime_flag[stoi(ok)]==1)
            {
                cout<<2<<endl;
                cout<<ok<<endl;return;
            }
        }
        cout<<2<<endl;
        cout<<str[0]<<str[K-1]<<endl;
    }
}
int main()
{
    calculate_prime_flag();
    ll T;
    cin >> T;
    while (T-- > 0)
    {
        solve();
    }
    // your code goes here
    return 0;
}
