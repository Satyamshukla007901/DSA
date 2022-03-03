//A
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
    unordered_set<ll> sat;
    sat.insert(6);sat.insert(13);sat.insert(20);sat.insert(27);
    unordered_set<ll> sun;
    sun.insert(7);sun.insert(14);sun.insert(21);sun.insert(28);
    ll cnt = sat.size()+sun.size();
    for(auto &value:vp)
    {
        if(sat.find(value)==sat.end()&&sun.find(value)==sun.end())
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
//B
void solve()
{
    ll N;
    cin>>N;
    if(N==2)
    {
        cout<<-1<<endl;return;
    }
    if(N==4)
    {
        cout<<4<<" "<<1<<" "<<3<<" "<<2<<endl;return;
    }
    if(N%2==0)
    {
        cout<<4<<" ";
        for(int i=1;i<=N;i++)
        {
            if(i!=4)
                cout<<i<<" ";
        }
        cout<<endl;return;
    }
    for(int i=1;i<=N;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}