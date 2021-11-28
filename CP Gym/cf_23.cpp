#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, n;
    cin >> a >> b >> n;
    // long long count=0;
    // bool flag = false;
    // long long num = a;
    // while(count!=n)
    // {
    //     flag=false;
    //     for(long long i=0;i<=9&&count!=n;i++)
    //     {
    //         if(((num*10) + i)%b==0)
    //         {
    //             num = (num*10) + i;
    //             count++;
    //             flag=true;
    //         }
    //     }
    //     if(!flag)
    //     {
    //         cout<<"-1"<<endl;
    //         break;
    //     }
    // }
    // if(flag==true)
    //     cout<<num<<endl;
    // long long count = 0;
    // bool flag = true;
    // for (int i = 0; i <= 9;)
    // {
    //     if(count==n)
    //         break;
    //     if (a % b != 0)
    //     {
    //         a = a * 10 + i;
    //         flag = true;
    //         count++;
    //         i++;
    //     }
    //     else
    //     {
    //         if (flag != false)
    //         {
    //             cout << a;
                
    //         }
    //         flag=false;
    //         if (i % b == 0)
    //         {
    //             cout << i;
    //             count++;
    //         }
    //         else
    //             i++;
    //     }
    // }
    // if(flag)
    //     cout<<-1<<endl;
    bool flag = true;
    for(int i=0;i<10;)
    {
        if(((a*10 )+ i )%b==0)
        {
            flag = false;
            cout<<((a*10)+i);
            a = a*10+i;
            n--;
            break;
        }
        else
        {
            i++;
        }
    }
    if(flag)
    {
        cout<<-1<<endl;
    }
    else
    {
        while(n>0)
        {
            cout<<0;
            n--;
        }
    }
    cout<<endl;
}