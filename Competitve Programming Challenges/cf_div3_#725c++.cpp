//A - https://codeforces.com/contest/1538/problem/A
void solve()
{
    ll N;
    cin >> N;
    vector<ll> vp;
    ll maxe = INT_MIN;
    ll mine = INT_MAX;
    ll idx_max = -1;
    ll idx_min = -1;
    for (int i = 1; i <= N; i++)
    {
        ll X;
        cin >> X;
        vp.push_back(X);
        if (X > maxe)
        {
            maxe = X;
            idx_max = i - 1;
        }
        if (X < mine)
        {
            mine = X;
            idx_min = i - 1;
        }
    }
    ll min_step;ll sum = 0;
    if((idx_min-0+1)<(N-1-idx_min+1))
    {
        min_step = idx_min-0+1;
    }
    else    
        min_step = N-1-idx_min+1;
    
    ll max_step;
    if((idx_max-0+1)<(N-1-idx_max+1))
    {
        max_step = idx_max-0+1;
    }
    else    
        max_step = N-1-idx_max+1;
    if(min_step<max_step)
    {
        sum+=min_step;
        if(min_step==idx_min-0+1)
        {
            sum+=min(idx_max-idx_min,N-1-idx_max+1);
        }
        else
        {
            sum+=min(idx_max-0+1,idx_min-idx_max);
        }
    }
    else
    {
        sum+=max_step;
        if(max_step==idx_max-0+1)
        {
            sum+=min(idx_min-idx_max,N-1-idx_min+1);
        }
        else
        {
            sum+=min(idx_min-0+1,idx_max-idx_min);
        }
    }
    cout<<sum<<endl;
}

//B - https://codeforces.com/contest/1538/problem/B
void solve()
{
   ll N;
   cin>>N;
   vector<ll> vp;map<int,int> mp;ll sum = 0;
   for(int i=1;i<=N;i++)
   {
       ll X;
       cin>>X;sum+=X;
       vp.push_back(X);mp[X]++;
   }
   if(N==1||(mp.size()==1&&N>1))
   {
       cout<<0<<endl;
   }
   else if(sum%N!=0)
   {
       cout<<-1<<endl;
   }
   else
   {
       ll cnt = 0;
       for(auto &value:vp)
       {
           if(value>(sum/N))
           {
               cnt++;
           }
       }
       cout<<cnt<<endl;
   }
}