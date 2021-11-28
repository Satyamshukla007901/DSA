#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, s;
    cin >> m >> s;
    int sum = s;
    int t;
    if(s==0&&m==1)
        cout<<0<<" "<<0<<endl;
    else if (s >= 1 && s <= m * 9)
    {
        if (s == m&&s>9)
        {
            map<int, int> mp;
            map<int, int, greater<int>> dmp;
            int a = 9;
            int num = 0;
            while (sum != 0)
            {
                if (sum / a != 0)
                {
                    mp.insert({a, sum / a});
                    dmp.insert({a, sum / a});
                    num += sum / a;
                }

                sum %= a;
                a--;
            }
            // for(auto &value:mp)
            //     cout<<value.first<<" "<<value.second<<endl;
            // cout<<"--------------"<<endl;
            // for(auto &value:dmp)
            //     cout<<value.first<<" "<<value.second<<endl;
            int zeroes = m - num;
            // auto it = mp.begin();
            // cout<<(*it).first;
            // ((*it).second)--;
            // for(int i=1;i<=zeroes;i++)
            //     cout<<0;
            for (auto &value : mp)
            {
                for (int i = 1; i <= value.second; i++)
                    cout << value.first;
                break;
            }
            for (int i = 1; i <= zeroes; i++)
                cout << 0;
            bool flag = false;
            for (auto &value : mp)
            {
                if (!flag)
                {
                    flag = true;
                    continue;
                }
                for (int i = 1; i <= value.second; i++)
                    cout << value.first;
            }
            cout << " ";
            for (auto &value : dmp)
            {
                for (int i = 1; i <= value.second; i++)
                    cout << value.first;
            }
            for (int i = 1; i <= zeroes; i++)
                cout << 0;
            cout << endl;
        }
        else
        {
            for (int i = 1; i <= m; i++)
            {
                if (i == 1)
                    t = 1;
                else
                    t = 0;
                for (int j = t; j <= 9; j++)
                {
                    if (i == m)
                    {
                        cout << sum;
                        break;
                    }
                    else if (sum - j <= 9 && sum - j >= 0)
                    {
                        cout << j << "";
                        sum -= j;
                        break;
                    }
                }
            }
            cout << " ";
            sum = s;
            int temp;
            for (int i = 1; i <= m; i++)
            {
                if (i == 1)
                    temp = 1;
                else
                    temp = 0;
                for (int j = 9; j >= temp; j--)
                {
                
                    if (sum - j >= 0)
                    {
                        cout << j << "";
                        sum -= j;
                        break;
                    }
                }
            }
            cout << endl;
        }
    }
    else
        cout << -1 << " " << -1 << endl;

    return 0;
}