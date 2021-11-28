#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int N;
        cin >> N;
        string str="";
        for(int i=1;i<=N;i++)
        {
            str+="(";
        }
        for(int i=1;i<=N;i++)
        {
            str+=")";
        }
        cout<<str<<endl;
        for(int i=1;i<N;i++)
        {
            for(int j=N-i;j<=N+i-1;j++)
            {
                if(str[j]==')')
                    str[j]='(';
                else
                    str[j]=')';
            }
            cout<<str<<endl;
        }
    }
    return 0;
}