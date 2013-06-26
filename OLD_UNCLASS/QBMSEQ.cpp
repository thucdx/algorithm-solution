#include <iostream>
#include <cmath>
using namespace std;

int f(int n);
int prev,d,maxD;
bool isPrevOk;
int n,a;

int main()
{
    freopen("input.txt","rt", stdin);
    freopen("output.txt", "wt", stdout);
    maxD=0;
    prev=-1;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        int val=f(a);
        //cout<<a<<" "<<val<<endl;
        if(val!=-1) //la 1 so thuoc day
        {
            if(isPrevOk) 
            {   
                if(val>=prev)
                {
                    d++;    
                    
                }
                else
                {
                    d=1;    
                }
                prev=val;
            }
            else
            {
                prev=val;
                d=1;    
            } 
            isPrevOk=true;  
        }
        else
        {   
            if(d>maxD) maxD=d;
            isPrevOk=false;
            d=0;
            prev=-1;    
        }
    } 
    cout<<maxD;   
        
}
int f(int n)
{   
    int k;
    n*=2;
    k=sqrt(n);
    if(k*(k+1)==n) return k;
    return -1;
}
