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
//Genreate balanced Parathewsis
//https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1#
void solve(int o, int c, string &op, vector<string> &ans)
{
    if (o == 0 && c == 0)
    {
        ans.push_back(op);
        return;
    }
    if (o != 0)
    {
        string op1 = op;
        op1 += "(";

        solve(o - 1, c, op1, ans);
    }

    if (c > o)
    {
        string op2 = op;
        op2 += ")";

        solve(o, c - 1, op2, ans);
    }
    return;
}

public:
vector<string> AllParenthesis(int n)
{
    int o = n;
    int c = n;
    string op = "";
    vector<string> ans;
    solve(o, c, op, ans);
    return ans;
    // Your code goes here
}
//Print N bit Binary Number Such That #1's >= #0's
//https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1#
void solve(int o, int z, string &ok, vector<string> &ans, int N)
{
    if (N == 0)
    {
        ans.push_back(ok);
        return;
    }

    if (o > z)
    {
        string op1 = ok;
        string op2 = ok;
        op1 += "1";
        op2 += "0";
        solve(o + 1, z, op1, ans, N - 1);
        solve(o, z + 1, op2, ans, N - 1);
    }
    else if (o == z)
    {
        string op1 = ok;
        op1 += "1";
        solve(o + 1, z, op1, ans, N - 1);
    }
    return;
}
vector<string> NBitBinary(int N)
{
    int o = 1;
    int z = 0;
    string op = "1";
    vector<string> ok;
    solve(o, z, op, ok, N - 1);
    return ok;
    // Your code goes here
}
//Josephus Problem
//https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1#
void solve(vector<int> &vp, int k, int idx, int &ans)
{
    if (vp.size() == 1)
    {
        ans = vp[0];
        return;
    }
    idx = (idx + k) % vp.size();
    vp.erase(vp.begin() + idx);
    solve(vp, k, idx, ans);
}
int safePos(int n, int k)
{

    vector<int> vp;
    for (int i = 1; i <= n; i++)
        vp.push_back(i);
    int index = 0;
    int ans = -1;
    solve(vp, k - 1, index, ans);
    return ans;
    // code here
}
//Phone Pad Probelm
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
void solve(string digits, string &op, vector<string> &ans, string map[])
{
    if (digits == "")
    {
        ans.push_back(op);
        return;
    }
    int val = digits[0] - '0';
    string valu = map[val];
    digits.erase(digits.begin() + 0);
    for (int i = 0; i < valu.length(); i++)
    {
        string op1 = op;
        op1 += valu[i];
        solve(digits, op1, ans, map);
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;

    if (digits == "")
        return ans;
    string op = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, op, ans, mapping);
    return ans;
}
//https://leetcode.com/problems/permutations/submissions/
//Permutations
void solve(vector<int> nums, vector<int> &op, vector<vector<int>> &ans)
{
    if (nums.size() == 0)
    {
        ans.push_back(op);
        return;
    }
    vector<int> temp = nums;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> help = op;
        help.push_back(nums[i]);
        nums.erase(nums.begin() + i);
        solve(nums, help, ans);
        nums = temp;
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ok;
    solve(nums, ok, ans);
    return ans;
}
//Improved Space Complexity
void solve(vector<int> nums, int idx, vector<vector<int>> &ans)
{
    /* My approach Space complexity is O(N)+ stack space
        if(nums.size()==0)
        {
            ans.push_back(op);
            return;
        }
        vector<int> temp = nums;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> help = op;
            help.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            solve(nums,help,ans);
            nums=temp;
            
        }*/

    if (idx >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        solve(nums, idx + 1, ans);
        swap(nums[i], nums[idx]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ok;
    solve(nums, 0, ans);
    return ans;
}