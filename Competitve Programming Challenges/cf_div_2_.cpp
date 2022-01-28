void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;
    for (int i = 1; i <= N; i++)
    {
        ll X;
        cin >> X;
        vp.push_back(X);
    }
    ll ans = 0;
    for(int i=0;i<N-1;i++)
    {
        ans=max(ans,vp[i]*vp[i+1]);
    }
    cout<<ans<<endl;
}

void solve()
{
    ll N, K;
    cin >> N >> K;
    string str;
    cin >> str;
    if (K == 0)
    {
        cout << "YES" << endl;
    }
    else if(2*K==N)
        cout<<"NO"<<endl;
    else
    {
        for(int i=0;i<K;i++)
        {
            if(str[i]!=str[N-i-1])
            {
                cout<<"NO"<<endl;return;
            }
        }
        cout<<"YES"<<endl;
    }
}