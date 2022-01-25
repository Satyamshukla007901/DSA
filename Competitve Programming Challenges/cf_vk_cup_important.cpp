//remeber to observe from the test cases 
//seconly when u want to construct a decimal number from a binary decimal number you need atleast (max digit) binary deicmal numbers
//
/*
Name : Satyam Shukla
*/
//A - >https://codeforces.com/contest/1530/problem/A
void solve()
{
    ll N;
    cin >> N;
    if (N < 10)
        cout << N << endl;
    else
    {
        string str = to_string(N);
        ll cnt0 = 0;
        ll cnt1 = 0;
        for (auto &value : str)
        {
            cnt0 += (value == '0');
            cnt1 += (value == '1');
        }
        if (cnt0 + cnt1 == str.length())
        {
            cout << 1 << endl;
        }
        else
        {
            ll maxe = 0;
            while(N!=0)
            {
                maxe = max(maxe,N%10);
                N/=10;
            }
            cout<<maxe<<endl;
        }
    }
}
//B -> https://codeforces.com/contest/1530/problem/B
void solve()
{
    ll H, W;
    cin >> H >> W;
    char arr[H][W];
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            arr[i][j] = '0';
        }
    }
    arr[0][0] = '1';
    arr[0][W - 1] = '1';
    arr[H - 1][0] = '1';
    arr[H - 1][W - 1] = '1';
    //1st row
    for (int i = 1; i < W - 1; i++)
    {
        if (arr[0][i - 1] != '1' && arr[0][i + 1] != '1')
        {
            arr[0][i] = '1';
        }
    }
    //last row
    for (int i = 1; i < W - 1; i++)
    {
        if (arr[H - 1][i - 1] != '1' && arr[H - 1][i + 1] != '1')
        {
            arr[H - 1][i] = '1';
        }
    }
    //1st Column
    for (int i = 1; i < H - 1; i++)
    {
        if (arr[i - 1][0] != '1' && arr[i + 1][0] != '1')
        {
            arr[i][0] = '1';
        }
    }
    //last column
    for (int i = 1; i < H - 1; i++)
    {
        if (arr[i - 1][W - 1] != '1' && arr[i + 1][W - 1] != '1')
        {
            arr[i][W - 1] = '1';
        }
    }
 
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << arr[i][j];
        cout << endl;
    }
    cout << endl;
}