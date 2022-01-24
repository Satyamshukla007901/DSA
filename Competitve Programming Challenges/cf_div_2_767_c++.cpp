//A - https://codeforces.com/contest/1629/problem/A
void solve()
{
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> a;
    vector<ll> b;vector<pair<ll,ll>> vp;
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
        vp.push_back({a[i-1],X});
    }
    sort(vp.begin(),vp.end());
    ll idx=0;
    while(idx<N&&vp[idx].first<=K)
    {
        K+=vp[idx].second;
        idx++;
    }
    cout<<K<<endl;
}
//B - https://codeforces.com/contest/1629/problem/B
void solve()
{
    ll L, R, K;
    cin >> L >> R >> K;
    ll cnt = 0;
    if(L==R&&L==1)
    {
        cout<<"NO"<<endl;return;
    }
    else if(L==R&&L!=1)
    {
        cout<<"YES"<<endl;return;
    }
    if (L % 2 == 0 && R % 2 == 0)
    {
        cnt += (R - L + 1) / 2;
    }
    else if (L % 2 != 0 && R % 2 != 0)
    {
        cnt += (R - L + 1) / 2 + 1;
    }
    else if (L % 2 == 0 || R % 2 == 0)
    {
        if ((R - L + 1) % 2 == 0)
        {
            cnt += (R - L + 1) / 2;
        }
        else
        {
            cnt += (R - L + 1) / 2;
        }
    }
    if (cnt > K)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}