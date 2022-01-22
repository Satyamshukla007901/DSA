//A - https://codeforces.com/contest/1535/problem/A
void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<ll> vp;
    vp.push_back(a);
    vp.push_back(b);
    vp.push_back(c);
    vp.push_back(d);
    sort(vp.begin(),vp.end());
    ll maxs = vp[3];
    ll mins = vp[2];
    if (((maxs == a || maxs == b) && (mins == a || mins == b)) || ((maxs == c || maxs == d) && (mins == c || mins == d)))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}
//B - https://codeforces.com/contest/1535/problem/B
void solve()
{
   ll N;
   cin>>N;
   ll idx = 1;
   vector<ll> vp;ll sum = 0;vector<ll> odd;
   for(int i=0;i<N;i++)
   {
       ll X;
       cin>>X;
       if(X%2==0)
       {
           sum+=(N-idx);idx++;
       }
       else if(X%2!=0)
       {
           odd.push_back(X);
       }
       vp.push_back(X);
   }
   sort(odd.begin(),odd.end());
   for(int i = 0;i<odd.size();i++)
   {
       for(int j=i+1;j<odd.size();j++)
       {
           if(odd[i]!=1)
           {
               if(odd[j]%odd[i]==0||__gcd(odd[i],odd[j])>1)
               {
                   sum++;
               }
           }
       }
   }
   cout<<sum<<endl;
 
}