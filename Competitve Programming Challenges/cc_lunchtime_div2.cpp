//A -https://www.codechef.com/problems/PLPROCESS
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        ll X;
        cin >> X;sum+=X;
        vp.push_back(X);
    }
    ll ans = sum;
    vector<ll> pre(N,0);
    pre[0]=vp[0];
    for(int i=1;i<N;i++)
    {
        pre[i]=pre[i-1]+vp[i];
    }
    for(int i=0;i<N;i++)
    {
        ans=min(ans,max(pre[i],sum-pre[i]));
    }
    cout<<ans<<endl;
}
//B -https://www.codechef.com/problems/DISTCON
void solve()
{
    ll D;
    cin>>D;
    //four points need to be in circle so the diameter need to be even for points to be integer
    if(D%2!=0)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<0<<" "<<D/2<<endl;
        cout<<D/2<<" "<<0<<endl;
        cout<<D/2<<" "<<D<<endl;
        cout<<D<<" "<<D/2<<endl;
    }
}
//C -https://www.codechef.com/problems/MAGNETSORT
https://www.codechef.com/viewsolution/59369901