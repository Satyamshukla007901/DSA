//Submission Accepted
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    ll N;
    cin >> N;
    // vector<ll> hr;
    // vector<ll> min;
    // for(int i=0;i<N;i++)
    // {
    //     ll hour;
    //     cin>>hour;
    //     hr.push_back(hour);
    //     ll minute;
    //     cin>>minute;
    //     min.push_back(minute);
    // }
    ll cash = 1;
    map<pair<ll, ll>, ll> mp;
    for (int i = 0; i < N; i++)
    {
        ll hour;
        cin >> hour;
        ll minute;
        cin >> minute;
        mp[{hour, minute}]++;
    }
    // map<ll,ll> mpf;
    // for(auto &value:mp)
    // {
    //     mpf[value.second]++;
    // }
    // cash = mpf.size();
    ll count = 0;
    for (auto &value : mp)
    {
        value.second--;
        count += (value.second == 0);
    }
    // for(auto &value:mp)
    //     cout<<value.second<<" ";
    // cout<<endl;
    // cout<<count<<endl;
    while (count != mp.size())
    {
        for (auto &value : mp)
        {
            if(value.second!=0)
            {
                value.second--;
                
                count += (value.second == 0);
            }   
        }
        cash++;
    }

    cout << cash << endl;
}
