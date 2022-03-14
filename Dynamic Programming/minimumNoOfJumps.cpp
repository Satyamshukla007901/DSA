//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1/?page=2&difficulty[]=-1&difficulty[]=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions#
    int minJumps(int arr[], int n){
        int ok = 0;
        int end = 0;int curr = 0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]+i>curr)
            {
                curr = arr[i]+i;
            }
            if(end == i)
            {
                
                ok++;
                end = curr;
            }
            

        }
        if(end<n-1)
            return -1;
        return ok;
        // Your code here
    }

//Explanation: If we want to reach the end of the array so in our every range we have
// to choose that jump whcih will make us reach the farthest point