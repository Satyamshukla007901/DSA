#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int N;
    cin >> N;
    vector<int> vp;int sum=0;
    int one = 0, two = 0, three = 0, four = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        vp.push_back(x);
        one += (x == 1);
        two += (x == 2);
        three += (x == 3);
        four += (x == 4);
    }
    // cout<<one<<two<<three<<four<<endl;
    sum+=four;
    sum+=three;
    if(one<=three)
        one=0;
    else
        one-=three;
    if(two%2==1)
    {
        sum+=(two/2)+1;
        one-=2;
    }
    else if(two%2==0)
    {
        sum+=(two/2);
    }
    
    // cout<<sum<<endl;
    if(one>0)
    {
        if(one%4==1||one<4)
            sum+=(one/4)+1;
        else
            sum+=one/4;

    }
    cout << sum << endl;
}