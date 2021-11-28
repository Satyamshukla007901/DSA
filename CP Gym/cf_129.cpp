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

void solve()
{
        int N;
        cin>>N;
        string A;
        string B;
        cin>>A;
        cin>>B;
        int ans=0;int res=0;
        bool flag = false;
        for(int i=N-1;i>=0;i--)
        {
            if(A[i]<B[i])
            {
                ans++;
                flag=true;
            }
            else if(A[i]>B[i])
            {
                flag=false;
            }
            else
            {
                if(flag)
                    ans++;
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
