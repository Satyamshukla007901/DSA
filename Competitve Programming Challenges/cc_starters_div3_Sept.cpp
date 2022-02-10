//A - https://www.codechef.com/problems/VACCINQ
void solve()
{
    ll N, P, X, Y;
    cin >> N >> P >> X >> Y;
    vector<ll> vp(N + 1);
    for (int i = 1; i <= N; i++)
    {
        ll X;
        cin >> X;
        vp[i]=X;
    }
    ll sum = 0;
    for (int i = 1; i <= P; i++)
    {
        if (vp[i] == 1)
        {
            sum += Y;
        }
        else
            sum += X;
    }
    cout << sum << endl;
}
//B - https://www.codechef.com/problems/MAGDOORS
void solve()
{
    string str;
    cin >> str;
    ll l = str.length();
    if(l==1)
    {
        if(str[0]=='0')
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    else
    {
        if(str[0]=='0')
        {
            ll cnt = 0 ;
            for(int i=0;i<l;i++)
            {
                if(i+1<l)
                {
                    if(str[i]=='0'&&str[i+1]=='1')
                    {
                        cnt++;
                    }
                    else if(str[i]=='1'&&str[i+1]=='0')
                    {
                        cnt++;
                    }
                }
            }
            cout<<cnt+1<<endl;
        }
        else
        {
            ll cnt = 0 ;
            for(int i=0;i<l;i++)
            {
                if(i+1<l)
                {
                    if(str[i]=='0'&&str[i+1]=='1')
                    {
                        cnt++;
                    }
                    else if(str[i]=='1'&&str[i+1]=='0')
                    {
                        cnt++;
                    }
                }
            }
            cout<<cnt<<endl;
        }
    }
}
//C - https://www.codechef.com/problems/DIWALI1
void solve()
{
    ll P, a, b, c, x, y;
    cin >> P >> a >> b >> c >> x >> y;
    ll coeff1 = a*x+b;
    ll coeff2 = a*y+c;
    cout<<max(P/coeff1,P/coeff2)<<endl;
}