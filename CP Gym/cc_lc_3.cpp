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
int main()
{
    ll T;
    cin >> T;
    while (T-- > 0)
    {
        ll N, P, K;
        cin >> N >> P >> K;
        ll res = 0;
        ll range = P % K;
        range--;
        ll X = (((N-1)/K)*K);
        X = N - 1 - X;
        if (range > X)
        {
            res += (X + 1) * ((N - 1) / K + 1) + (range - X) * ((N - 1) / X);
        }
        else
        {
            res += ((N - 1) / K + 1) * (range + 1);
        }
        for (ll i = range + 1; range <= N - 1; i += K)
        {
            res++;
            if (i == P)
            {
                cout << res << endl;
                break;
            }
        }
    }
    return 0;
}
