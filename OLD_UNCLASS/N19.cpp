#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    freopen("ANS.OUT","wt", stdout);  
    long long n=2*555666777888999ll;
    //long long n=2*99;
    int lim=sqrt(n);
    int d;
    for(d=lim;d>=1;d--)
    {   
        //cout<<d<<endl;
        if((n%d==0))
        {
            int thuong=n/d;
            if((thuong%2 + d%2)==1)
            {
                cout<<"Result: "<<(thuong-d-1)/2<<" "<<d<<" "<<thuong<<endl;  
                return 0;  
            }
        }        
    }
    
    
}
