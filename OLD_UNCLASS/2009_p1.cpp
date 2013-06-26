// Olympic
#include <iostream>
using namespace std;

long long one, two, three;
int n;
long long rs;
int main()
{   
    freopen("SEQ.INP", "rt", stdin);
    freopen("SEQ.OUT", "wt", stdout);
    one =two=three=-1000000005ll;
    scanf("%d",&n);
    long long num;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&num);
        if(num>one)
        {
            three=two;
            two=one;
            one=num;    
        }
        else if(num>two)
        {
            three=two;
            two=num;    
        }    
        else if(num>three)
        {
            three=num;    
        }
    }
    cout<<one<<"\n"<<two<<"\n"<<three<<endl;
    cout<<(one*3+two*2+three);
}
