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
        ll A[101] = {0};
        ll l, r, k;
        cin >> l >> r >> k;
        ll temp = r - l + 1;
        if (temp == 1)
            cout << 1 << endl;
        else
        {
           cout<<k<<endl;
        }
    }
    return 0;
}
