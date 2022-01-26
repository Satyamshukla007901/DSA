//https://leetcode.com/problems/valid-parentheses/
bool isValid(string s)
{

    int l = s.length();
    stack<char> st;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (st.empty() != true)
            {
                char ch = st.top();
                st.pop();
                if (ch == '(')
                {
                }
                else
                    return false;
            }
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (st.empty() != true)
            {
                char ch = st.top();
                st.pop();
                if (ch == '[')
                {
                }
                else
                    return false;
            }
            else
                return false;
        }
        else if (s[i] == '}')
        {
            if (st.empty() != true)
            {
                char ch = st.top();
                st.pop();
                if (ch == '{')
                {
                }
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (st.empty() == false)
        return false;
    return true;
}

//Min Stack leetcode
int tp = -1;
int arr[100000];
MinStack()
{
    tp = -1;
}

void push(int val)
{
    tp++;
    arr[tp] = val;
}

void pop()
{
    if (tp != -1)
        tp--;
}

int top()
{
    if (tp != -1)
        return arr[tp];
    return -1;
}

int getMin()
{

    int mine = INT_MAX;
    for (int i = 0; i <= tp; i++)
    {
        mine = min(mine, arr[i]);
    }
    return mine;
}

//stock span problem
vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans(n);
    ans[0] = 1;
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - st.top();
        }
        st.push(i);
    }
    return ans;
    // Your code here
}

//Maximum ectangular Area
https : //practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#
        long long
        getMaxArea(long long arr[], int n)
{
    vector<long long> nsl(n);
    stack<int> st;
    st.push(0);
    nsl[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (!st.empty() && arr[st.top()] >= arr[i])
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
            {
                nsl[i] = -1;
            }
            else
                nsl[i] = st.top();
        }
        else if (st.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            nsl[i] = st.top();
        }
        st.push(i);
    }
    // for(auto &value:nsl)
    //     cout<<value<<" ";
    // cout<<endl;
    while (!st.empty())
        st.pop();
    vector<long long> nsr(n);
    nsr[n - 1] = n;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (!st.empty() && arr[st.top()] >= arr[i])
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                nsr[i] = n;
            else
                nsr[i] = st.top();
        }
        else if (st.empty())
            nsr[i] = n;
        else
            nsr[i] = st.top();
        st.push(i);
    }
    // for(auto &value:nsr)
    //     cout<<value<<" ";
    // cout<<endl;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i] * (nsr[i] - nsl[i] - 1));
    }
    return ans;
    // Your code here
}

//Maximum Area in a binary Matrix
//https://leetcode.com/problems/maximal-rectangle/submissions/
long long getMaxArea(vector<long long> arr, int n)
{
    vector<long long> nsl(n);
    stack<int> st;
    st.push(0);
    nsl[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (!st.empty() && arr[st.top()] >= arr[i])
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
            {
                nsl[i] = -1;
            }
            else
                nsl[i] = st.top();
        }
        else if (st.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            nsl[i] = st.top();
        }
        st.push(i);
    }
    // for(auto &value:nsl)
    //     cout<<value<<" ";
    // cout<<endl;
    while (!st.empty())
        st.pop();
    vector<long long> nsr(n);
    nsr[n - 1] = n;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (!st.empty() && arr[st.top()] >= arr[i])
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                nsr[i] = n;
            else
                nsr[i] = st.top();
        }
        else if (st.empty())
            nsr[i] = n;
        else
            nsr[i] = st.top();
        st.push(i);
    }
    // for(auto &value:nsr)
    //     cout<<value<<" ";
    // cout<<endl;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i] * (nsr[i] - nsl[i] - 1));
    }
    return ans;
    // Your code here
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int ans = INT_MIN;
    vector<long long> vp(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '0')
            {
                vp[j] = 0;
            }
            else
            {
                vp[j]++;
            }
        }
        ans = max((long long)ans, getMaxArea(vp, vp.size()));
    }
    return ans;
}


//Trapping Rainwater
//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
long long trappingWater(int arr[], int n)
{
    vector<int> leftmax(n);
    leftmax[0]=arr[0];
    for(int i=1;i<n;i++)
        leftmax[i]=max(arr[i],leftmax[i-1]);
    vector<int> rightmax(n);
    rightmax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rightmax[i]=max(arr[i],rightmax[i+1]);
    }
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        ans+=abs(arr[i]-min(leftmax[i],rightmax[i]));
    }
    return ans;
    // code here
}