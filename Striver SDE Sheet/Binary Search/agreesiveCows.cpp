//https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=1
int aggressiveCows(vector<int> &stalls, int k)
{
    int s = 0;
    int e = *(max_element(stalls.begin(),stalls.end()));int ans;
    sort(stalls.begin(),stalls.end());
    e-=stalls[0];
    while(s<=e)
    {
        int mid = s + (e-s)/2;int idx=0;int count=1;
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-stalls[idx]>=mid)
            {
                idx=i;
                count++;
               if(count==k)
                   	break;
            }
        }
        if(count==k)
        {
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
    //    Write your code here.
}