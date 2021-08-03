#include <bits/stdc++.h>
using namespace std;
//String Palindrome Check
int isPlaindrome(string S)
{
    int l = S.length();
    for (int i = 0; i < l; i++)
    {
        if (S[i] != S[l - i - 1])
            return 0;
    }
    return 1;
    // Your code goes here
}
//duplicates Counting with character in the string
void duplicates(string S)
{
    unordered_map<char, int> ump;
    int l = S.length();
    for (int i = 0; i < l; i++)
    {
        ump[S[i]]++;
    }
    for (auto &value : ump)
    {
        cout << value.first << " " << value.second << endl;
    }
    return;
}
//String S1 is Rotation of String S2
bool areRotations(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    string temp = s1 + s1;
    auto it = temp.find(s2);
    if (it != string::npos)
        return true;
    else
        return false;
    // Your code here
}
//Count And Say
string countAndSay(int n)
{
    if(n==1)
        return "1";
    string S = countAndSay(n-1);
    vector<pair<char,int>> sp;
    string ans="";
    for(int i=0;i<S.length();)
    {
        int count=1;
        for(int j=i+1;j<S.length();j++)
        {
            if(S[j]!=S[i])
                break;
            if(S[i]==S[j])
                count++;
        }
        // bool flag = false;
        // for(auto &value:sp)
        // {
        //     if(S[i]==value.first)
        //     {
        //         flag=true;
        //         break;
        //     }
        // }
        // if(flag)
        // {

        // }
        // else
        sp.push_back({S[i],count});  
        i+=count;
    }
    // for(int i=0;i<S.length();i++)
    // {
    //     um[S[i]]++;
    // }
    for(auto &value:sp)
    {
        ans+=to_string(value.second)+value.first;
    }

    return ans;
}
int32_t main()
{
    // string S;
    // cin >> S;
    // cout<<isPlaindrome(S)<<endl;
    // duplicates(S);
    int N;
    cin>>N;
    cout<<countAndSay(N)<<endl;
}