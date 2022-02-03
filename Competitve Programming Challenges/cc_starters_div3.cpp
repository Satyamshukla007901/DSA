//A - https://www.codechef.com/problems/BADMINTON
void solve()
{
      ll N;
      cin>>N;
      ll sum = 0;
      sum+=N/2;
      sum++;
      cout<<sum<<endl;
}
//B - https://www.codechef.com/problems/EVMHACK
void solve()
{
    ll A, B, C, P, Q, R;
    cin >> A >> B >> C >> P >> Q >> R;
    ll a1 = P-A;
    ll b1 = Q-B;
    ll c1 = R-C;ll tot = P+Q+R;
    if(A+B+C>tot/2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        
        if(P+B+C>tot/2)
        {
            cout<<"YES"<<endl;
        }
        else if(A+Q+C>tot/2)
        {
            cout<<"YES"<<endl;
        }
        else if(A+B+R>tot/2)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}
// C - https://www.codechef.com/problems/ORANDCON
void solve()
{
    ll N;
    cin>>N;
    vector<ll> vp(32);
    ll num = N;vector<ll> p(32);
    for(int i=0;i<32;i++)
    {
        if((N>>i)&1)
        {
            vp[i]=1;
            p[i]=1;
        }
    }
    cout<<N<<" ";
    vector<ll> b = vp;
    for(int i=0;i<32;i++)
    {
        if(b[i]==0)
        {
            p[i]=1;
            b[i]=1;break;
        }
    }
    ll B=0;
    for(int i=0;i<32;i++)
    {
        B=B+pow(2,i)*b[i];
    }
    vector<ll> c = vp;
    for(int i=0;i<32;i++)
    {
        if(c[i]==0&&p[i]==0)
        {
            c[i]=1;
            break;
        }
    }
    ll C=0;
    for(int i=0;i<32;i++)
    {
        C=C+pow(2,i)*c[i];
    }
    cout<<B<<" "<<C<<endl;
    
}
// D - https://www.codechef.com/problems/ANTI_PAL
void solve()
{
    ll N;
    cin >> N;
    string str;
    cin >> str;
    if (N % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        map<char, int> mp;
        for (auto &value : str)
        {
            mp[value]++;
        }
        if (mp.size() == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            bool flag = true;
            for (auto &value : mp)
            {
                if (value.second > N / 2)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
                string s = "";
                for(auto &value:mp)
                {
                    for(int i=1;i<=value.second;i++)
                    {
                        s+=value.first;
                    }
                }
                for(int i=0;i<N/2;i++)
                {
                    cout<<s[i];
                }
                for(int i=N-1;i>=N/2;i--)
                {
                    cout<<s[i];
                }
                cout<<endl;
                
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    
}
//E - https://www.codechef.com/problems/DIVREC
void solve()
{
     ll X,A,B;
     cin>>X>>A>>B;
     if(X%A!=0)
     {
          cout<<-1<<endl;
     }
     else if(A==1)
     {
          if(X==1&&B==1)
          {
               cout<<1<<endl;
          }
          else
               cout<<-1<<endl;
     }
     else
     {
          cout<<(X*B)/A<<endl;
     }
}