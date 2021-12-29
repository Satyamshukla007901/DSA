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