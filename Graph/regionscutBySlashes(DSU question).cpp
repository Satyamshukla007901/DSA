//https://leetcode.com/problems/regions-cut-by-slashes/submissions/
class Solution {
public:
    void union_( int a, int b, int par[], int rank[]) 
    {
        a =find(a,par);
        b =find(b,par);
        if(rank[a]<rank[b])
        {
            par[a] = b;
            
        }
        else if(rank[a]>rank[b])
        {
            par[b] = a;
        }
        else
        {
            par[b]=a;
            rank[b]++;
        }
        //code here
    }
    int find(int x,int par[])
    {
        if(x==par[x]) return x;
        
        return par[x] = find(par[x],par);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int dots = n+1;
        int par[dots*dots];
        int rank[dots*dots];
        for(int i=0;i<dots*dots;i++)
        {
            par[i]=i;
            rank[i]=0;
        }
        int cnt = 0;
        for(int i=0;i<dots;i++)
        {
            for(int j=0;j<dots;j++)
            {
                int key = dots*i+j;
                if(key!=0 and (i==0||j==0||i==dots-1||j==dots-1))
                     union_(0,key,par,rank);
            }
        }
        
        cnt++;// whole circle is one component;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    int key1 = i*dots+j+1;
                    int key2 = (i+1)*dots+j;
                    if(find(key1,par)==find(key2,par)) cnt++;
                    union_(key1,key2,par,rank);
                }
                else if(grid[i][j]=='\\')
                {
                    int key1 = i*dots+j;
                    int key2 = (i+1)*dots+j+1;
                    if(find(key1,par)==find(key2,par)) cnt++;
                    union_(key1,key2,par,rank);
                }
                
            }
           
        }
         return cnt;
    }
};