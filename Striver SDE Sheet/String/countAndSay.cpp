//https://leetcode.com/problems/count-and-say/
// TC-->O(N*|str|)
// Sc--->O(stack space)
string f(int n)
{
    if(n==1) return "1";
    
    string ok = f(n-1);
    string ans = "";
    for(int i=0;i<ok.length();i++)
    {
        int cnt = 1;
        while(i+1<ok.length() and ok[i]==ok[i+1]){ cnt++;i++;}
        ans+=to_string(cnt);
        ans+=ok[i];
    }
    return ans;
}

// Tc-->O(N*|str|)
// SC-->O(1)

    string ok = "1";
    
    for(int i=2;i<=n;i++)
    {
        string temp = "";
        for(int j=0;j<ok.length();j++)
        {
            int cnt = 1;
            while(j+1<ok.length() and ok[j]==ok[j+1])
            {
                cnt++;j++;
            }
            temp+=to_string(cnt);
            temp+=ok[j];
        }
        ok=temp;
    }
    return ok;