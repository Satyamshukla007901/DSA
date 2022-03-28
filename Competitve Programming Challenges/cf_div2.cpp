//A ->https://codeforces.com/contest/1658/problem/A
void solve()
{
    ll N;
    cin >> N;
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (i + 1 < N && str[i] == '0' && str[i + 1] == '0')
        {
            cnt += 2;
        }
        else if (i + 2 < N && str[i] == '0' && str[i + 1] == '1' && str[i + 2] == '0')
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}
//B ->https://codeforces.com/contest/1658/problem/B
void solve()
{
    ll N;
    cin>>N;
    if(N&1)
    {
        cout<<0<<endl;return;
    }
    ll ok = N/2;
    ll ans = 1;
    for(ll i=1;i<=ok;i++)
    {
        ans = (ans * i)%mod;
        ans = ans%mod;
    }
    cout<<((ans%mod)*(ans%mod))%mod<<endl;
 
}