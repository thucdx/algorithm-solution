//Tinh B_n
#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}
struct Q{
    int x,y;
    Q(){x=0;y=1;}
    Q(int _x, int _y) {
        int uoc=gcd(abs(_x),abs(_y));
        x=_x/uoc;
        y=_y/uoc;
    }
    Q operator+(Q that)
    {
        int tu=x*that.y+y*that.x;
        int mau=y*that.y;
        if(mau<0)
        {
            tu*=-1;
            mau*=-1;    
        }
        int uoc=gcd(abs(tu),abs(mau));
        tu/=uoc;
        mau/=uoc;
        return Q(tu,mau);    
    }
    Q operator-(Q that)
    {
        int tu=x*that.y-y*that.x;
        int mau=y*that.y;
        if(mau<0)
        {
            tu*=-1;
            mau*=-1;    
        }
        int uoc=gcd(abs(tu),abs(mau));
        tu/=uoc;
        mau/=uoc;
        return Q(tu,mau);  
            
    }
    void operator=(Q that)
    {
         x=that.x;
         y=that.y;   
    }
    Q operator*(int k)
    {
        return Q(x*k, y);    
    }
};
Q a[105];Q b(int n)
{
    for(int m=0;m<=n;m++)
    {
        a[m]=Q(1,m+1);
        for(int j=m;j>=1;j--)
        {
            a[j-1]=(a[j]-a[j-1])*j;
        }
    }
    return a[0];
}
int main()
{
    freopen("BenoulliNumber.OUT", "wt", stdout);
    for(int i=1;i<=100;i++)
    {
        Q tmp;;
        tmp=b(i);
        cout<<i<<" "<<tmp.x<<"/"<<tmp.y<<endl;    
    }
    
}
