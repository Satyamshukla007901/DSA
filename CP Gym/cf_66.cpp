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
#define LIMIT 10000000
long long i, j;
long long prime_flag[LIMIT];
void calculate_prime_flag()
{
    prime_flag[0] = prime_flag[1] = 1;
    for (i = 2; i < LIMIT; i++)
    {
        if (prime_flag[i] == 0)
        {
            for (j = i * i; j < LIMIT; j += i)
            {
                prime_flag[j] = 1;
            }
        }
    }
}
bool check_prime(ll X)
{
    if (X % 2 == 0)
        return false;
    for (ll i = 3; i <= sqrt(X); i += 2)
    {
        if (X % i == 0)
            return false;
    }
    return true;
}
int main()
{
    fasio;
    calculate_prime_flag();
    ll T;
    cin >> T;
    while (T-- > 0)
    {
        ll X, Y;
        cin >> X >> Y;
        ll count = 0;
        while (X < Y)
        {
            if (X % 2 == 0)
            {
                count++;
                X++;
            }
            else
            {
                if (check_prime(X + 2))
                {
                    X = X + 2;
                    count++;
                }
                else
                {
                    X += 1;
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
    // your code goes here
    return 0;
}
