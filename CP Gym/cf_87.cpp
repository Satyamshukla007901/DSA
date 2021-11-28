#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int32_t main()
{
    ll N,M;
    cin>>N>>M;
    if(N>M)
    {
        cout<<N-M<<endl;
    }
    else if(N==M)
        cout<<0<<endl;
    else
    {
        ll count=0;
        
        while(N!=M)
        {
            if(N*2>M)
            {
                N-=1;
                count++;
            }
            else
            {
                N*=2;
                count++;
                if(N==M)
                    break;
                if(N!=2)
                {
                   
                    N-=1;
                    count++; 
                }
          
            }
            

        }
        cout<<count<<endl;

    }

}