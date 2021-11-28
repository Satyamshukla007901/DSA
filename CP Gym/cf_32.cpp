#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int N,j;
        cin>>N>>j;
        string S;
        cin>>S;
        int pt1 = -1;
        int pt2 = j-1;
        int i=pt2;
        bool flag = false;
        while(pt1!=pt2&&i<N)
        {
             if(pt2==N)
            {
                flag=true;
                break;
            }

            if(S[i+1]=='.')
            {
                pt2++;
            }
            else if(S[i+1]=='#')
            {
                S[i+1]='.';
            }
            pt1++;

           
            if(pt1==pt2)
            {
                flag = false;
                break;
            }
            i++;
        }
        cout<<pt1<<" "<<pt2<<endl;
        if(flag)
            cout<<"JAY"<<endl;
        else if(pt1==pt2)
        {
            cout<<"JEFF"<<endl;
        }
        else
        {
            cout<<"JAY"<<endl;
        }
    }
    return 0;
}