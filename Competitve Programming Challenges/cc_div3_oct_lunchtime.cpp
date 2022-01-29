//A-https://www.codechef.com/problems/PROBCAT
void solve()
{
     ll X;
     cin>>X;
     if(X>=1&&X<100)
     {
          cout<<"Easy"<<"\n";
     }
     else if(X>=100&&X<200)
     {
          cout<<"Medium"<<"\n";
     }
     else
     {
          cout<<"Hard"<<"\n";
     }
}
//B-https://www.codechef.com/problems/ALTER
void solve()
{
     ll A,B,P,Q;
     cin>>A>>B>>P>>Q;
     if(P%A!=0||Q%B!=0)
     {
          cout<<"NO"<<endl;
     }
     else
     {
          ll a = P/A;
          ll b = Q/B;
          if(abs(a-b)<=1)
          {
               cout<<"YES"<<endl;
          }
          else
          {
               cout<<"NO"<<endl;
          }
     }
}
//C-https://www.codechef.com/problems/N1VALUES
void solve()
{
    ll N;
    cin >> N;
    if(N==1)
    {
        cout<<1<<" "<<1<<endl;return;
    }
    cout<<1<<" ";
    for(int i=0;i<N;i++)
    {
        cout<<(1LL<<i)<<" ";
    }
    cout<<endl;
    // 1152921504606847000
}
//D-https://www.codechef.com/problems/CHEFCAR
void solve()
{
    ll N, V;
    cin >> N >> V;
    ll max = (N*(N-1))/2;
    ll temp = N-1;ll min;
    if(temp<=V)
    {
        min = temp;
    }
    else
    {
        min=V;
        ll destination = N-V;
        ll ok = (destination*(destination+1))/2;
        ok--;
        min+=ok;
    }
    cout<<max<<" "<<min<<endl;
}