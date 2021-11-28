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
        if (prime_flag[i] == 0)
        {
            for (j = i * i; j < LIMIT; j += i)
            {
                prime_flag[j] = 1;
            }
        }
    }
}
int main()
{
    fasio;
    ll T;
    cin >> T;
    while (T-- > 0)
    {
        ll N;
        cin >> N;
        vector<ll> C;
        vector<ll> zero;
        vector<ll> one;
        ll sum0 = 0;
        ll sum1 = 0;
        for (int i = 0; i < N; i++)
        {
            ll x;
            cin >> x;
            C.push_back(x);
            sum0 += (i % 2 == 0) ? x : 0;
            sum1 += (i % 2 == 1) ? x : 0;
            if (x % 2 == 0)
            {

                zero.push_back(x);
            }
            else
                one.push_back(x);
        }
        sort(zero.begin(), zero.end(), greater<int>());
        sort(one.begin(), one.end(), greater<int>());
        int a = 0;
        ll sum = 0;
        if (zero.size() == 0 || one.size() == 0)
        {

            for (auto &value : one)
                cout << value << " ";
            cout << endl;
            for (auto &value : zero)
                cout << value << " ";
            cout << endl;
        }
        else
        {
            for (int i = 0; i < zero.size() && a < one.size(); i++)
            {
                cout << zero[i] << " " << one[a] << " ";
            }
            cout << endl;
        }
        a = 0;
        for (int i = 0; i < zero.size(); i++)
        {

            for (int j = a; j < one.size(); j++)
                sum += (zero[i] * one[j]);
            a++;
        }

        cout << sum << endl;
    }
    // your code goes here
    return 0;
}
