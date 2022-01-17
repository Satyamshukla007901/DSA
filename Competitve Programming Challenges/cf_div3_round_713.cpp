//A - https://codeforces.com/contest/1512/problem/A
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
    cin >> N;
    vector<ll> vp;
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        ll X;
        cin >> X;
        vp.push_back(X);
        mp[X]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (mp[vp[i]] == 1)
        {
            cout << i + 1 << endl;
            return;
        }
    }
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

//B - https://codeforces.com/contest/1512/problem/B
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
    cin >> N;
    vector<vector<char>> vp;
    int a1, b1, a2, b2;
    vector<int> ok;
    for (int i = 0; i < N; i++)
    {
        vector<char> lol;
        for (int j = 0; j < N; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                ok.push_back(i);
                ok.push_back(j);
            }
            lol.push_back(ch);
        }
        vp.push_back(lol);
    }
    a1 = ok[0]; //row 1st *
    b1 = ok[1]; //col 1st *
    a2 = ok[2]; //row 2nd *
    b2 = ok[3]; //col 2nd *
    if (b1 == b2)
    {
        if (b1 - 1 >= 0 && b2 - 1 >= 0)
        {
            vp[a1][b1 - 1] = '*';
            vp[a2][b2 - 1] = '*';
        }
        else
        {
            vp[a1][b1 + 1] = '*';
            vp[a2][b2 + 1] = '*';
        }
    }
    else if (a1 == a2)
    {
        if (a1 - 1 >= 0 && a2 - 1 >= 0)
        {
            vp[a1 - 1][b1] = '*';
            vp[a2 - 1][b2] = '*';
        }
        else
        {
            vp[a1 + 1][b1] = '*';
            vp[a2 + 1][b2] = '*';
        }
    }
    else
    {
        vp[a1][b2] = '*';
        vp[a2][b1] = '*';
    }
    for (auto &value : vp)
    {
        for (auto &val : value)
        {
            cout << val;
        }
        cout << endl;
    }
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

//C
//https://codeforces.com/contest/1512/problem/C
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
    ll A, B;
    cin >> A >> B;
    ll a = A, b = B;
    string str;
    cin >> str;
    for (auto &value : str)
    {
        if (value == '0')
        {
            A--;
        }
        else if (value == '1')
        {
            B--;
        }
    }
    // cout<<A<<" "<<B<<endl;
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        if (str[i] != str[j] && str[i] == '?' && str[j] == '0')
        {
            if (A <= 0)
            {
                cout << -1 << endl;
                return;
            }
            str[i] = '0';
            A--;
        }
        else if (str[i] != str[j] && str[i] == '?' && str[j] == '1')
        {
            if (B <= 0)
            {
                cout << -1 << endl;
                return;
            }
            str[i] = '1';
            B--;
        }
        else if (str[i] != str[j] && str[i] == '0' && str[j] == '?')
        {
            if (A <= 0)
            {
                cout << -1 << endl;
                return;
            }
            str[j] = '0';
            A--;
        }
        else if (str[i] != str[j] && str[i] == '1' && str[j] == '?')
        {
            if (B <= 0)
            {
                cout << -1 << endl;
                return;
            }
            str[j] = '1';
            B--;
        }
        // cout<<A<<" "<<B<<endl;
        i++;
        j--;
    }
    i = 0;
    j = str.length() - 1;
    while (i < j)
    {
        if (str[i] == str[j] && str[i] == '?' && str[j] == '?')
        {
            if (A >= 2)
            {
                str[i] = '0';

                A--;

                str[j] = '0';
                A--;
            }
            else if (B >= 2)
            {
                str[i] = '1';

                B--;

                str[j] = '1';
                B--;
            }
        }
        i++;
        j--;
    }
    if (str.length() % 2 == 1 && str[str.length() / 2] == '?')
    {
        if (A == 1)
        {
            str[str.length() / 2] = '0';
        }
        else if (B == 1)
        {
            str[str.length() / 2] = '1';
        }
    }
    for (auto &value : str)
    {
        if (value == '?')
        {
            cout << -1 << endl;
            return;
        }
    }
    i = 0;
    j = str.length() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            cout << -1 << endl;
            return;
        }
        i++;
        j--;
    }
    int cnt0 = 0, cnt1 = 0;
    for (auto &value : str)
    {
        cnt0 += (value == '0');
        cnt1 += (value == '1');
    }
    if (cnt0 != a || cnt1 != b)
    {
        cout << -1 << endl;
        return;
    }
    cout << str << endl;
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
