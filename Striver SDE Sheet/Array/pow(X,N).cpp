//https://leetcode.com/problems/powx-n/submissions/
class Solution {
public:

    double myPow(double x, int n) {
        if(n==1)
                return x;
        else if(n==0)
                return 1;
        if(n<0)
        {
            x=1/x;
            n=abs(n);
        }
        double ok = myPow(x,n/2);
        ok*=ok;
        if(n%2!=0)
        {
            ok=x*ok;
        }
        return ok;
    }
};