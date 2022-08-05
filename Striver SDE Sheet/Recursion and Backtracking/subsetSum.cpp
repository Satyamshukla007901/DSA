//https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include <bits/stdc++.h>
using namespace std;

void countFreq(long long int arr[], int x)
{
	unordered_map<int, int> mp;

	// Traverse through array elements and
	// count frequencies
	for (int i = 0; i < x; i++)
		mp[arr[i]]++;

    vector<pair<int,int>>vec;
    for(auto x : mp){
        vec.push_back({x.second,x.first});
    }
    long long int ok=vec.size();
    sort(vec.begin(),vec.end());
    if(ok==1){
        cout<<(vec[ok-1].first+1)/2<<"\n";
    }
    else{
        if(vec[ok-1]==vec[ok-2]){
            cout<<vec[ok-1].first<<"\n";
        }
        else{
            vec[ok-1].first=(vec[ok-1].first+1)/2;
            sort(vec.begin(),vec.end());
            cout<<vec[ok-1].first<<"\n";
        }

    }

}	

int main()
{
    long long int t;
    cin>>t;
    while(t--){
        long long int x;
        cin>>x;

        long long int arr[x];
        for(long long int i=0;i<x;i++){
            cin>>arr[i];
        } 
        
        countFreq(arr, x);

    }
	return 0;
}