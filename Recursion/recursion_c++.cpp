#include <bits/stdc++.h>
//print 1 to N by recursion
void printN(int N)
{
    if (N == 0)
        return;
    printN(N - 1);
    cout << N << " ";
}
//Sort an Array
void insert(vector<int> &vp, int ok)
{
    if (vp.size() == 0 || vp[vp.size() - 1] <= ok)
    {
        vp.push_back(ok);
        return;
    }
    int val = vp[vp.size() - 1];
    vp.pop_back();
    insert(vp, ok);
    vp.push_back(val);
}
void sort(vector<int> &vp)
{
    if (vp.size() == 1)
        return;
    int temp = v[v.size() - 1];
    v.pop_back();
    sort(vp);
    insert(v, temp);
}
//Sort a stack usign recursion
//Geeks for geesks me hai
void sInsert(stack<int> &st, int item)
{
    if (st.size() == 0 || st.top() <= item)
    {
        st.push(item);
        return;
    }
    int ok = st.top();
    st.pop();
    sInsert(st, item);
    st.push(ok);
}
void SortedStack ::sort()
{
    if (s.empty())
        return;
    int ok = s.top();
    s.pop();
    sort();
    sInsert(s, ok);
    //Your code here
}
//Delete middle element of stack
//https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
void ok(stack<int> &st, int mid)
{

    if (mid == 0)
    {
        st.pop();
        return;
    }
    int item = st.top();
    st.pop();
    ok(st, mid - 1);
    st.push(item);
}
void deleteMid(stack<int> &s, int sizeOfStack)
{
    int mid = sizeOfStack / 2;

    ok(s, mid);
}
//kth grammer
//https://leetcode.com/problems/k-th-symbol-in-grammar/submissions/
int kthGrammar(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    if (k > pow(2, n - 1) / 2)
    {
        return !kthGrammar(n, k - pow(2, n - 1) / 2);
    }
    else
    {
        return kthGrammar(n - 1, k);
    }
}
//Tower of hanoi
//https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1#
long long cnt = 0;
long long toh(int N, int from, int to, int aux)
{
    cnt++;
    if (N == 1)
    {
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        return cnt;
    }

    toh(N - 1, from, aux, to);
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    toh(N - 1, aux, to, from);
    return cnt;
    // Your code here
}
//Power Set
//https://practice.geeksforgeeks.org/problems/power-set4302/1/
void solve(string inp, string op, vector<string> &ok)
{
    if (inp == "")
    {
        if (op != "")
            ok.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2 += inp[0];
    inp.erase(inp.begin() + 0);
    solve(inp, op1, ok);
    solve(inp, op2, ok);
}
vector<string> AllPossibleStrings(string s)
{
    vector<string> vp;

    string op = "";
    solve(s, op, vp);
    sort(vp.begin(), vp.end());
    return vp;
    // Code here
}
//bit masking approach
vector<string> AllPossibleStrings(string s)
{
    int n = s.length();
    vector<string> ok;
    int total = pow(2, n);
    for (int i = 0; i < total; i++)
    {
        string op = "";
        for (int j = 0; j < n; j++)
        {
            //  cout<<(i&(1<<j))<<endl;
            if ((i & (1 << j)) == pow(2, j))
            {

                op += s[j];
            }
        }
        if (op != "")
            ok.push_back(op);
    }
    sort(ok.begin(), ok.end());
    return ok;
}
//Print Unique
//https://practice.geeksforgeeks.org/problems/subsets-1587115621/1
void solve(string inp, string op, vector<string> &ok)
{
    if (inp == "")
    {
        if (op != "")
            ok.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2 += inp[0];
    inp.erase(inp.begin() + 0);
    solve(inp, op1, ok);
    solve(inp, op2, ok);
}
vector<vector<int>> AllSubsets(vector<int> arr, int n)
{
    vector<string> vp;
    string s = "";
    for (auto &value : arr)
    {
        s += to_string(value);
    }
    string op = "";
    solve(s, op, vp);
    sort(vp.begin(), vp.end());
    set<string> ss;
    for (auto &value : vp)
    {
        sort(value.begin(), value.end());
        ss.insert(value);
    }
    vector<string> ans;
    for (auto &value : ss)
        ans.push_back(value);
    vector<vector<int>> ok;
    ok.push_back(vector<int>());
    for (auto &value : ans)
    {
        vector<int> temp;
        for (auto &val : value)
        {
            temp.push_back(val - '0');
        }
        ok.push_back(temp);
    }

    return ok;
    // code here
}
//Permutation With Space
//https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1#
void solve(string str, string &op, vector<string> &ok)
{
    if (str == "")
    {
        if (op != "")
            ok.push_back(op);
        return;
    }
    string op1 = op;
    op1 += str[0];
    string op2 = op;
    op2 += " ";
    op2 += str[0];
    str.erase(str.begin() + 0);
    solve(str, op1, ok);
    solve(str, op2, ok);
}
vector<string> permutation(string S)
{
    vector<string> ans;
    string op = "";
    op += S[0];
    S.erase(S.begin() + 0);
    solve(S, op, ans);
    sort(ans.begin(), ans.end());
    return ans;
    // Code Here
}
//LEtter Case Permutation
///https://leetcode.com/problems/letter-case-permutation/submissions/
void solve(string s, string &op, vector<string> &ok)
{
    if (s == "")
    {
        ok.push_back(op);
        return;
    }
    if (s[0] >= '0' && s[0] <= '9')
    {
        string op1 = op;
        op1 += s[0];
        s.erase(s.begin() + 0);
        solve(s, op1, ok);
        return;
    }
    else
    {
        string op1 = op;
        string op2 = op;
        op1 += s[0];
        if (s[0] >= 'a' && s[0] <= 'z')
            op2 += s[0] - 'a' + 'A';
        else
            op2 += s[0] - 'A' + 'a';
        s.erase(s.begin() + 0);
        solve(s, op1, ok);
        solve(s, op2, ok);
    }
    return;
}
vector<string> letterCasePermutation(string s)
{
    vector<string> vp;
    string op = "";
    solve(s, op, vp);
    return vp;
}