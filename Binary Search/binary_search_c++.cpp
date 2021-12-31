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
int Search(vector<int> arr, int n, int x)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
            return mid;
        else if (mid - 1 >= s && arr[mid - 1] == x)
            return mid - 1;
        else if (mid + 1 <= e && arr[mid + 1] == x)
            return mid + 1;
        else if (arr[mid] <= x)
            start = mid + 2;
        else
            end = mid - 2;
    }
    return -1;
}
//Find Floor of an Element in a sorted array
//https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
int findFloor(vector<long long> v, long long n, long long x)
{

    int s = 0;
    int ans = -1;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (v[mid] <= x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;

    // Your code here
}
//https://leetcode.com/problems/find-smallest-letter-greater-than-target/submissions/
//Next greater letter
char nextGreatestLetter(vector<char> &letters, char target)
{
    int s = 0;
    int n = letters.size();
    int e = n - 1;
    char ans = letters[0];
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (letters[mid] > target)
        {
            ans = letters[mid];
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}
//find peak element index
//https://leetcode.com/problems/find-peak-element/submissions/
int findPeakElement(vector<int> &nums)
{

    int n = nums.size();
    if (n == 1)
        return 0;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid - 1 >= 0 && mid + 1 < n && nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;
        else if (mid + 1 < n && nums[mid] < nums[mid + 1])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if (nums[0] > nums[1])
        return 0;
    return n - 1;
}
//Find Maximum Element in a biotonic array(array which is wither increasing or decreasing or both)
//https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1
int findMaximum(int arr[], int n)
{
    return arr[findPeakElement(arr, n)];// Its the same function as above so dont get confused just u need only to change the paramenters from vector to array
    // code here
}