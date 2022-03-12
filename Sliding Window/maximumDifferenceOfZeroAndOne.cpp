//similar to kadane
https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
	int maxSubstring(string S)
	{
	    int cnt1 = 0;
	    for(auto &value:S)
	        cnt1+=(value=='1');
	    if(cnt1==S.length())
	        return -1;
	    int sum = 0;
	    int currsum = 0;
	    for(int i=0;i<S.length();i++)
	    {
	        if(S[i]=='0')
	            currsum+=1;
	        else
	            currsum+=-1;
	        sum=max(sum,currsum);
	        if(currsum<0)
	            currsum=0;
	    }
	    return sum;
	    // Your code goes here
	}