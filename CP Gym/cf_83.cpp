#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int l = S.length();
    string str = "";
    transform(S.begin(), S.end(), S.begin(), ::tolower);

    if (S[0] == 'a' || S[0] == 'e' || S[0] == 'i' || S[0] == 'o' || S[0] == 'u' || S[0] == 'y')
    {
        str="";
    }
    else
        str=str+"."+S[0];
    for (int i = 1; i < l; i++)
    {
        if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' || S[i] == 'y')
        {
        }
        else
        {
            str =  str+"." + S[i];
        }
    }
    cout << str << endl;

    return 0;
}