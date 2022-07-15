//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long arr[], long long l, long long m, long long r)
    {
        long long cnt = 0;
        long long sz1 = m-l+1;
        long long sz2 = r-m;
        
        long long arr1[sz1];long long arr2[sz2];
        for(long long i=0;i<sz1;i++)
            arr1[i]=arr[l+i];
            
        for(long long i=0;i<sz2;i++)
            arr2[i]=arr[m+1+i];
        long long i,j;
        i=0;
        j=0;
        long long k=l;
        while(i<sz1&&j<sz2)
        {
            if(arr1[i]<=arr2[j])
            {
                arr[k]=arr1[i];
                i++;
            }
            else
            {
                arr[k]=arr2[j];
                j++;
                cnt+=(sz1-i);
            }
            k++;
        }
        while(i<sz1)
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
        
        while(j<sz2)
        {
            arr[k]=arr2[j];
            j++;
            k++;
        }
        return cnt;
         // Your code here
    }
    
    long long mergeSort(long long arr[], long long l, long long r)
    {
        if(l<r)
        {
            long long mid = l+(r-l)/2;
            long long a =  mergeSort(arr,l,mid);
            long long b = mergeSort(arr,mid+1,r);
            long long c = merge(arr,l,mid,r);
            
            return a+b+c;
        }
        return 0;
        //code here
    }
    long long int inversionCount(long long arr[], long long N)
    {
       
        
        return mergeSort(arr,0,N-1);
        
        
        // Your Code Here
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends