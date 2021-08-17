
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
vector<int> separateNegativeAndPositive(vector<int> &nums){
    // vector<int> ans;
    // for(int i=0;i<nums.size();i++)
    // {
    //     if(nums[i]<0)
    //         ans.push_back(nums[i]);
    // }
    // for(int i=0;i<nums.size();i++)
    // {
    //     if(nums[i]>=0)
    //         ans.push_back(nums[i]);
    // }
    // return ans;
    int left = 0,right = nums.size()-1;
    while(left<=right)
    {
        if(nums[left]<0&&nums[right]<0)
        {
            left++;
        }

        else if(nums[right]<0&&nums[left]>0)
        {
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
        else if(nums[left]>0&&nums[right]>0)
        {
            right--;
        }
        else{
            left++;
            right--;
        }
    }
    return nums;
    // Write your code here.
}
void rotate(int arr[], int n)
{
    int first = arr[0];
    arr[0]=arr[n-1];
    for(int i=n-1;i>=1;i--)
    {
        if(i==1)
        {
            arr[i]=first;
        }
        else
        {
            arr[i]=arr[i-1];
        }
    }
}
// First and last occurrences of x
vector<int> find(int arr[], int n , int x )
{
    int start=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            start=i;
            break;
        }
    }
    int end=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==x)
        {
            end=i;
            break;
        }
    }
    vector<int> vp;
    vp.push_back(start);
    vp.push_back(end);
    return vp;
    // code here
}
int main() {
    int N;
    cin>>N;
    int vp[N];
    for(int i=0;i<N;i++)
    {
        // int x;
        // cin>>x;
        // vp.push_back(x);
        cin>>vp[i];
    }
    // // vp = separateNegativeAndPositive(vp);
    // for(auto &value:vp)
    //     cout<<value<<" ";
    // cout<<endl;
    // vector<int> A = findf(vp,N,2);
    // for(auto &value:A)
    // {
    //     cout<<value<<" ";
    // }
    // cout<<endl;
	// your code goes here
	return 0;
}


