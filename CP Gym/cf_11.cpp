#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long t;
    cin>>t;
    long long res;
    while(t-->0)
    {
        long long n;
        cin>>n;
        //If slices is less than 6 then there is fixed time of 15 minutes
        if(n<=6)
            res = 15;
        //if the slices is odd then 
        //for each slide time is 2.5 min in every case 
        //for odd we must make it even
        else
        {
            if(n%2!=0)
                n++;
            res=(n*5)/2;
        }
        cout<<res<<endl;
    }
}