//A->https://www.codechef.com/problems/PREFPERM
void solve()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A;
    for (int i = 0; i < K; i++)
    {
        ll X;
        cin >> X;
        A.push_back(X);
    }
    ll ok = 1;
    for(auto &value:A)
    {
        cout<<value<<" ";
        while(ok<value)
        {
            cout<<ok<<" ";
            ok++;
        }
        ok=value+1;
    }
    cout<<endl;
}
//B->https://www.codechef.com/problems/PERFPERM
void solve()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> vp(N + 1);
    for (int i = 1; i <= N; i++)
    {
        vp[i] = i;
    }
    for (int i = K + 1; i <= N; i++)
    {
        if (i + 1 <= N)
        {
            swap(vp[i], vp[i + 1]);
        }
    }
    if(K==N-1)
    {
        swap(vp[1],vp[N]);
    }
    for (int i = 1; i <= N; i++)
    {
        cout << vp[i] << " ";
    }
    cout << endl;
}
//C->https://www.codechef.com/problems/PERMEX
void solve()
{
    ll N;
    cin >> N;
    string str;
    cin >> str;
    if (str[0] == '1' && str[1] == '1' && str[N] == '1')
    {
        cout << "YES" << endl;
        vector<ll> vp(N);
        vp[0]=0;
        vp[1]=1;
        for(int i=2;i<=N-1;i++)
        {
            if(str[i]=='0')
            {
                vp[i]=i;
                swap(vp[i],vp[i-1]);
            }
            else
            {
                vp[i]=i;
            }
        }
        for(auto &value:vp)
            cout<<value<<" ";
        cout<<endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}