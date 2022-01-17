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
    return arr[findPeakElement(arr, n)]; // Its the same function as above so dont get confused just u need only to change the paramenters from vector to array
    // code here
}
// Search in a Biotonic Array
//https://www.interviewbit.com/problems/search-in-bitonic-array/
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
int rBinarySearch(vector<int> arr, int l, int n, int x)
{
    int s = l;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}
int binarySearch(vector<int> arr, int r, int n, int x)
{
    int s = 0;
    int e = r;
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
int Solution::solve(vector<int> &A, int B)
{
    int N = A.size();
    int ok = A[findPeakElement(A)];
    if (B <= ok && B >= A[N - 1])
    {
        return rBinarySearch(A, findPeakElement(A), N, B);
    }
    else
    {
        return binarySearch(A, findPeakElement(A), N, B);
    }
    return -1;
}
//Search in a matrix
//https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1
int matSearch(int N, int M, int matrix[][M], int x)
{ ///O->(N+M)
    int i = 0;
    int j = M - 1;
    while (i < N && j >= 0)
    {
        if (matrix[i][j] == x)
            return 1;
        else if (matrix[i][j] > x)
            j--;
        else
            i++;
    }
    return 0;
}
//Kth Smallest number
//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/submissions/
class Solution
{
public:
    //Two Approaches se bana hai ywh questions ek verma ji ne karaya tha matrix sorted wala and dusra finding floor of a number
    bool isPossible(vector<vector<int>> &matrix, int k, int ans)
    {
        int cnt = 0;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            int s = 0;
            int e = matrix[0].size() - 1;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (matrix[i][mid] <= ans)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            cnt += s;
        }
        return cnt >= k;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {

        int r = matrix.size();
        int c = matrix[0].size();
        /*
        vector<int> vp(r*c);int idx = 0;
        for(auto &value:matrix)
        {
            for(auto &val:value)
            {
                vp[idx++]=val;
            }
        }
        sort(vp.begin(),vp.end());
       return vp[k-1];*/
        int s = matrix[0][0];
        int ans = -1;
        int e = matrix[r - 1][c - 1];
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isPossible(matrix, k, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};
//Book Allocation problem
//https://www.interviewbit.com/problems/allocate-books/
bool isValid(vector<int> A, int N, int K, int mid)
{
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (sum + A[i] <= mid)
        {
            sum += A[i];
        }
        else
        {
            cnt++;
            sum = A[i];
        }
    }
    cnt++;
    if (cnt > K)
        return false;
    return true;
}
int Solution::books(vector<int> &A, int B)
{
    int N = A.size();
    if (N < B)
        return -1;
    int ans = -1;
    int low = *max_element(A.begin(), A.end());
    int high = 0;
    for (auto &value : A)
        high += value;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(A, N, B, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
//Binary Search on Floats
//Cube root
double diff(double n, double mid)
{
    return abs(n - mid);
}
int cubeRoot(int N)
{
    double s = 0;
    double e = N;
    double p = 0.0000001;
    while (true)
    {
        double mid = s + (e - s) / 2;
        double error = diff(N, mid);
        if (error <= p)
            return (int)mid;
        else if ((mid * mid * mid) > N)
        {
            e = mid;
        }
        else
            s = mid;
    }
    return 0;
    // code here
}
//Interactive Binary Search problem
//https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/submissions/
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution
{
public:
    vector<vector<int>> findSolution(CustomFunction &customfunction, int z)
    {
        vector<vector<int>> ans;

        for (int i = 1; i <= 1000; i++)
        {
            int x = i;
            int s = 1;
            int e = 1000;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (customfunction.f(x, mid) == z)
                {
                    vector<int> temp(2);
                    temp[0] = x;
                    temp[1] = mid;
                    ans.push_back(temp);
                    break;
                }
                else if (customfunction.f(x, mid) < z)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }
        return ans;
    }
};
//single element in a sorted array
//https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        if (nums.size() == 1)
            return nums[0];
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (mid - 1 >= 0 && mid + 1 < nums.size() && nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
            {
                return nums[mid];
            }
            else if (mid + 1 < nums.size() && mid == 0 && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            else if (mid - 1 >= 0 && mid == nums.size() - 1 && nums[mid - 1] != nums[mid])
            {
                return nums[mid];
            }
            //Cacth of the Problem :-  first occurence of every duyplicate is at even index before single occurence element and first occurence of every duplicate is at odd index after single occurence elemnt
            else if (mid - 1 >= 0 && nums[mid - 1] == nums[mid])
            {
                if ((mid - 1) % 2 == 0)
                {
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }
            else
            {
                if ((mid + 1) % 2 == 0)
                {
                    e = mid - 1;
                }
                else
                    s = mid + 1;
            }
        }
        return 0;
    }
};