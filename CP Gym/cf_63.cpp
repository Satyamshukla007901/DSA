#include <bits/stdc++.h>
using namespace std;
class base
{
    public:
    int fun()
    {
        cout<<"Base::fun() called";
    }
    int fun(int i)
    {
        cout<<"base::fun(int i) called";
    }
};
class Derived: public base
{
    public:
    int fun()
    {
        cout<<"Derived::func() called";
        return (20);
    }
};
int main()
{
    Derived d;
    d.fun();
    return 0;
}




