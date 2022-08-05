//https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
	    sort(coins,coins+M);
	    int cnt = 0;
	    set<int> s;
	    for(int i=M-1;i>=0;i--)
	    {
	        
	        while(V>=coins[i])
	        {
	            V-=coins[i];
	            s.insert(coins[i]);
	        }
	        
	    }
	    return s.size();