//https://www.codechef.com/problems/THREEPTS
void solve()
{
        ll Xa,Ya;
        cin>>Xa>>Ya;
        ll Xb,Yb;
        cin>>Xb>>Yb;
        ll Xc,Yc;
        cin>>Xc>>Yc;
        if(Xa==Xc)
        {
            if(Xb==Xa&&Yb>=min(Ya,Yc)&&Yb<=max(Ya,Yc))
            {
                cout<<"YES"<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
        else if(Ya==Yc)
        {
            if(Yb==Ya&&Xb>=min(Xa,Xc)&&Xb<=max(Xa,Xc))
            {
                cout<<"YES"<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
        else
        {
            // cout<<(Yc>=Xc&&Yb<=Yc&&Yb>=Ya)<<endl;
            if(Xb==Xa&&((Yc>=Ya&&Yb<=Yc&&Yb>=Ya)||(Yc<=Ya&&Yb>=Yc&&Yb<=Ya)))
            {
                cout<<"YES"<<endl;
                //YES
            }
            else if(Yb==Yc&&((Xc>=Xa&&Xb>=Xa&&Xb<=Xc)||(Xc<=Xa&&Xb<=Xa&&Xb>=Xc)))
            {
                cout<<"YES"<<endl;
            }
            else if(Yb==Ya&&((Xc>=Xa&&Xb<=Xc&&Xb>=Xa)||(Xc<=Xa&&Xb>=Xc&&Xb<=Xa)))
            {
                cout<<"YES"<<endl;
            }
            else if(Xb==Xc&&((Yc>=Ya&&Yb>=Ya&&Yb<=Yc)||(Yc<=Ya&&Yb<=Ya&&Yb>=Yc)))
            {
                cout<<"YES"<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
}