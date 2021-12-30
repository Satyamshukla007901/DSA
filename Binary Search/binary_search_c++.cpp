#include <bits/sdtc++.h>
using namespace std;

int binarySearch(int arr[], int n, int x)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
//First and last Occurence
//https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
vector<int> find(int arr[], int n, int x)
{
    int f = -1;
    int l = -1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            f = mid;
            e = mid - 1;
        }
        else if (arr[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
    }
    s = 0;
    e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            l = mid;
            s = mid + 1;
        }
        else if (arr[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return {f, l};

    // code here
}
//Count number of Occurences
//https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
int count(int arr[], int n, int x)
{
    int f = -1;
    int l = -1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            f = mid;
            e = mid - 1;
        }
        else if (arr[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
    }
    s = 0;
    e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            l = mid;
            s = mid + 1;
        }
        else if (arr[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
    }
    if (l == -1 || f == -1)
        return 0;
    return l - f + 1;

    // code here
}
//Number of Times array is rotated
//https://practice.geeksforgeeks.org/problems/rotation4723/1#
int binarySearch(int arr[], int N)
{
    int s = 0;
    int e = N - 1;
    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[(mid - 1 + N) % N] > arr[mid] && arr[mid] < arr[(mid + 1) % N])
            return mid;
        else if (arr[mid] >= arr[0])
        {

            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return 0;
}
int findKRotation(int arr[], int n)
{

    if (n == 1)
        return 0;
    else if (arr[0] < arr[n - 1])
        return 0;

    return binarySearch(arr, n);

    // code here
}
//Search in Rotated Sorted Array
//https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
int pivot(vector<int> vp, int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (vp[(mid - 1 + n) % n] > vp[mid] && vp[mid] < vp[(mid + 1) % n])
            return mid;
        else if (vp[mid] >= vp[0])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return 0;
}

int bSearch(vector<int> vp, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vp[mid] == target)
            return mid;
        else if (vp[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int idx = pivot(nums, nums.size());
    if (n == 1)
    {
        if (nums[0] == target)
            return 0;
        return -1;
    }

    if (idx != -1 && target >= nums[idx] && target <= nums[n - 1])
    {
        return bSearch(nums, idx, n - 1, target);
    }
    else
        return bSearch(nums, 0, idx - 1, target);
    return -1;
}
//Search in Nearly Sorted Array
int Search(vector<int> arr,int n,int x)
{
    int s = 0;
    int e = n-1;
    while(s<=e)
    {   
        int mid = s + (e-s)/2;
        if(arr[mid]==x)
            return mid;
        else if(mid-1>=s&&arr[mid-1]==x)
            return mid-1;
        else if(mid+1<=e&&arr[mid+1]==x)
            return mid+1;
        else if(arr[mid]<=x)
            start = mid+2;
        else
            end=mid-2;
    }
    return -1;
}