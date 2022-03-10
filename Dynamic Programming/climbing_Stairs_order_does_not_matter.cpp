//https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1
		int nthStair(int n){
		    
		    vector<int> vp(n+1);
		    vp[0]=0;
		    vp[1]=1;
		    vp[2]=2;
		    for(int i=3;i<=n;i++)
		    {
		        vp[i]=vp[i-2]+1;
		    }
		    return vp[n];
		    
		    //  Code here
		}
//logical approach is using n/2+1