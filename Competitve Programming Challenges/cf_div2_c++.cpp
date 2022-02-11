//A - https://codeforces.com/contest/1537/problem/A
void solve()
{
    ll N;
    cin>>N;
    vector<ll> vp;
    for(int i=0;i<N;i++)
    {
        ll X;
        cin>>X;
        vp.push_back(X);
    }
    ll sum  = 0;
    for(int i=0;i<N;i++)
        sum+=vp[i];
    if(sum==N)
    {
        cout<<0<<endl;
    }
    else if(sum<0)
    {
        cout<<1<<endl;
    }
    else if(sum==0)
    {
        cout<<1<<endl;
    }
    else if(sum<N)
    {
        cout<<1<<endl;
    }
    else 
        cout<<abs(N-sum)<<endl;
}
//B - https://codeforces.com/contest/1537/problem/B
void solve()
{
    ll N, M, i, j;
    cin >> N >> M >> i >> j;
    ll sum = 0;
    sum = abs(i - 1) + abs(j - 1) + abs(N - 1) + abs(M - 1) + abs(i - N) + abs(j - M); // 1 1 N M
    ll x1 = 1, y1 = 1, x2 = N, y2 = M;
    //N 1 1 M
    ll x = abs(i - N) + abs(j - 1) + abs(N - 1) + abs(1 - M) + abs(i - 1) + abs(j - M);
    if (x > sum)
    {
        sum = x;
        x1 = N, y1 = 1, x2 = 1, y2 = M;
    }
    //1 1 1 M
    x = abs(i - 1) + abs(j - 1) + abs(M - 1) + abs(i - 1) + abs(j - M);
    if (x > sum)
    {
        sum = x;
        x1 = 1, y1 = 1, x2 = 1, y2 = M;
    }
    //N 1 N M
    x = abs(i - N) + abs(j - 1) + abs(M - 1) + abs(i - N) + abs(j - M);
    if (x > sum)
    {
        sum = x;
        x1 = N, y1 = 1, x2 = N, y2 = M;
    }
    //1 1 N 1
    x = abs(i - 1) + abs(j - 1) + abs(N - 1) + abs(i - N) + abs(j - 1);
    if (x > sum)
    {
        sum = x;
        x1 = 1, y1 = 1, x2 = N, y2 = 1;
    }
    //1 M N M
    x = abs(i - 1) + abs(j - M) + abs(N - 1) + abs(i - N) + abs(j - M);
    if (x > sum)
    {
        sum = x;
        x1 = 1, y1 = M, x2 = N, y2 = M;
    }
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
//C - https://codeforces.com/contest/1537/problem/C
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;
    map<ll, ll> mp;
    for (int i = 0; i < N; i++)
    {
        ll X;
        cin >> X;
        mp[X]++;
        vp.push_back(X);
    }
    sort(vp.begin(),vp.end());
    ll a = vp[0];
    ll b = vp[1];
    ll diff = b-a;
    ll i1= 0;
    ll i2=1;
    for(int i=0;i<N;i++)
    {
        if(i+1<N&&vp[i+1]-vp[i]<diff)
        {
            diff=vp[i+1]-vp[i];
            a=vp[i];
            i1=i;
            i2=i+1;
            b=vp[i+1];
        }
    }
    cout<<a<<" ";
    for(int i=i2+1;i<N;i++)
        cout<<vp[i]<<" ";
    for(int i=0;i<i1;i++)
    {
        cout<<vp[i]<<" ";
    }
    cout<<b<<endl;
}