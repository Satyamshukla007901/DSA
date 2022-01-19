//A - https://www.codechef.com/START11C/problems/FACEDIR
void solve()
{
     ll N;
     cin>>N;
     if(N%4==0)
     {
          cout<<"North"<<endl;
     }
     else if(N%4==1)
     {
          cout<<"East"<<endl;
     }
     else if(N%4==2)
     {
          cout<<"South"<<endl;
     }
     else
          cout<<"West"<<endl;
     
}
//B - https://www.codechef.com/START11C/problems/MAX_DIFF
void solve()
{
     ll N,S;
     cin>>N>>S;
     if(N==S)
     {
          cout<<S<<endl;
     }
     else if(S<N)
     {
          cout<<S<<endl;
     }
     else
     {
          cout<<2*N-S<<endl;
     }
}
//C - https://www.codechef.com/START11C/problems/BIGARRAY
void solve()
{
    ll N, S;
    cin >> N >> S;
    ll totSum = (N*(N+1))/2;
    if((totSum-S)>=1&&(totSum-S)<=N)
    {
        cout<<(totSum-S)<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
}
//D - https://www.codechef.com/START11C/problems/FILLGRID
void solve()
{
    ll N;
    cin >> N;
    if (N % 2 == 0)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cout << -1 << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                {
                    cout << -1 << " ";
                }
                else
                {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }
    }
}
