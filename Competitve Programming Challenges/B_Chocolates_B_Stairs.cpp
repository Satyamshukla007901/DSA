//https://codeforces.com/contest/1139/problem/B
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;
    for (int i = 0; i < N; i++)
    {
        ll X;
        cin >> X;
        vp.push_back(X);
    }
    ll sum = vp[N - 1];
    ll maxi = vp[N - 1] - 1;
    for (int i = N - 2; i >= 0; i--)
    {
        maxi = min(vp[i], maxi);
        sum += maxi;
        maxi=max(0LL,maxi-1);
    }
    cout << sum << endl;
}
//https://codeforces.com/contest/1244/problem/B
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;
    for (int i = 0; i < N; i++)
    {
        ll X;
        cin >> X;
        vp.push_back(X);
    }
    ll sum = vp[N - 1];
    ll maxi = vp[N - 1] - 1;
    for (int i = N - 2; i >= 0; i--)
    {
        maxi = min(vp[i], maxi);
        sum += maxi;
        maxi=max(0LL,maxi-1);
    }
    cout << sum << endl;
}