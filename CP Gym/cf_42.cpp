#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    
    int T;
    cin>>T;
    while(T-->0)
    {
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        int inp = A+B+C;
        if(inp <= D)
            cout<<1<<endl;
        else if((A+B)>D||(B+C)>D||(A+C)>D)
        {
            cout<<3<<endl;
        }
        else
            cout<<2<<endl;
    }
    return 0;
}