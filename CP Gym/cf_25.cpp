#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353
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
    int T;
    cin >> T;
    while (T-- > 0)
    {
        ll N, M;
        cin >> N >> M;
        ll A[N], B[M];
        ll sum_a=0,sum_b=0;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
            sum_a+=A[i];
        }
        for (int i = 0; i < M; i++)
        {
            cin >> B[i];
            sum_b+=B[i];
        }
        sum_a%=mod;
        sum_b%=mod;
        ll Query;
        cin >> Query;
        for (int k = 1; k <= Query; k++)
        {
            ll Q;
            cin >> Q;
            if (Q == 1)
            {
                ll L, R, X;
                cin >> L >> R >> X;
                sum_a += ((R-L+1)*X)%mod;
            }
            else if (Q == 2)
            {
                ll L, R, X;
                cin >> L >> R >> X;
                sum_b += ((R-L+1)*X)%mod;
            }
            else
            {
                // cout<<endl;
                // for(auto &value:A)
                //     cout<<value<<" ";
                // cout<<endl;
                // cout<<endl;
                // for(auto &value:B)
                //     cout<<value<<" ";
                // cout<<endl;
                // ll Score = 0;
                // ll sum = 0;
                // for (int i = 0; i < N; i++)
                //     sum += A[i];
                // for (int i = 0; i < M; i++)
                //     Score += (sum * B[i]);
                // cout << Score%mod<< endl;
                cout<<(sum_a*sum_b)%mod<<endl;
            }
        }
    }
    return 0;
}
