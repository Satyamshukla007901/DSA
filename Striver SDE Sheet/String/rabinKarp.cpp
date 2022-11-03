//TC -- best : O(N+M)   worst : O(NM)
//SC -- O(NM)

#define d 256
void search(string pat,string txt,int q)
{
    int M = pat.length();
    int N = txt.length();
    int i,j;
    int p = 0;
    int t = 0;
    int h = 1;
    for(int i=0;i<M-1;i++) h=(h*d)%q;
    for(int i=0;i<M;i++)
    {
        p = (d*p+pat[i])%q;
        t = (d*t+txt[i])%q;
    }

    for(int i=0;i<=N-M;i++)
    {
        if(p==t)
        {
            int j;
            for(j=0;j<M;j++)
            {
                if(txt[i+j]!=pat[j])
                {
                    break;
                }
            }
            if(j==M)
            {
                cout<<"found at index "<<i<<endl;
            }
        }

        if(i<N-M)
        {
            t=(d*(t-txt[i]*h)+txt[i+M])%q;
            if(t<0) t=t+q;
        }
    }
}