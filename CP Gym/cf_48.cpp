#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007
#define fasio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fori(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define elif else if
const ll INF=1e17;
const ll NINF=(-1)*INF;
int main() {
     ll T;
    cin>>T;
    while(T-->0)
    {
        ll N,D;
        cin>>N>>D;
        ll temp=N;
        string str = to_string(N);
        ll l = str.length();
        bool flag=false;
        while(temp!=0)
        {
            if(temp%10 == D)
            {
                flag=true;
                break;
            }
            temp/=10;
        }
        temp=N;
        if(flag)
        {
            if(D==0)
            {
                int idx=l;
                for(int i=0;i<l;i++)
                {
                    if(str[i]=='0')
                    {
                        str[i]='1';
                        idx=i;
                        break;
                    }
                }
                for(int i=idx+1;i<l;i++)
                    str[i]='1';
                
            }
            else if(D==9)
            {
                if(str[0]=='9')
                {
                    str="1"+str;
                    for(int i=1;i<l+1;i++)
                    {
                        str[i]='0';
                    }
                }
                else
                {
                    int idx=l;
                    for(int i=0;i<l;i++)
                    {
                        bool res=false;
                        if(str[i]=='9')
                        {

                            for(int j=i-1;j>=0;j--)
                            {
                                if(str[j]<='7')
                                {
                                    str[j]++;
                                    idx=j;
                                    res=true;
                                    break;
                                }
                                
                            }

                            if(!res)
                            {
                                for(int j=0;j<l;j++)
                                    str[j]='0';
                                str = '1'+str;
                            }
                            break;
                        }
                    }

                    for(int i=idx+1;i<l;i++)
                        str[i]='0';
                }
            }
            else
            {
                int idx=l;
                for(int i=0;i<l;i++)
                {
                    if((str[i]-47-1)==D)
                    {
                        str[i]++;
                        idx=i;
                        break;
                    }
                }

                for(int i=idx+1;i<l;i++)
                    str[i]='0';
                

            }
            cout<<stoll(str)-N<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
                       
    }
	// your code goes here
	return 0;
}
