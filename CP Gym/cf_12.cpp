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
    double res;
    while(T-->0)
    {
        
        int W,H;
        cin>>W>>H;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int w,h;
        cin>>w>>h;
        int temp1 = max(x1-0,W-x2);
        int temp2 = max(y1-0,H-y2);
        int X = W-x2+x1;
        int Y = H-y2+y1;
        int space_x = w-temp1;
        int space_y = h-temp2;
        if(space_x<0)
            space_x=0;
        if(space_y<0)
            space_y=0;
        // if(temp1>=w||temp2>=h)
        //     res = 0.0;
        // else if(X<w&&Y<h)
        // {
        //     res=-1.0;
        // }
        // else
        // {
        //     // res = sqrt(space_x*space_x + space_y*space_y);
        //     int dis_x=0,dis_y=0 ;
        //     if(X<w)//in x direction
        //     {
        //         dis_y = space_y;
        //     }
        //     else if(Y<h)//in y direction
        //     {
        //         dis_x = space_x;
        //     }
        //     else//in both direction
        //     {
        //         dis_x = space_x;
        //         dis_y = space_y;
        //         if(temp1>=w)
        //             dis_x = 0;
        //         if(temp2>=h)
        //             dis_y = 0;
        //     }
        //     res = sqrt(dis_x*dis_x + dis_y*dis_y);
        // }
        cout<<res<<endl;
    }
	// your code goes here
	return 0;
}
