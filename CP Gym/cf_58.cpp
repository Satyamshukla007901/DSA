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
    int T;
    cin>>T;
    while(T-->0)
    {
        vector<int> R;
        int R1,R2,R3,R4,R5;
        cin>>R1>>R2>>R3>>R4>>R5;
        R.push_back(R1);
        R.push_back(R2);
        R.push_back(R3);
        R.push_back(R4);
        R.push_back(R5);
        int india=0,england=0;
        for(auto &value:R)
        {
            if(value==1)
                india++;
            else if(value==2)
                england++;
        }
        if(india>england)
        {
            cout<<"INDIA"<<endl;
        }
        else if(england > india)
        {
            cout<<"ENGLAND"<<endl;
        }
        else
        {
            cout<<"DRAW"<<endl;
        }
    }
	// your code goes here
	return 0;
}
