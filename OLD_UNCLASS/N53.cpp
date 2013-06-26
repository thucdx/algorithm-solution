#include <iostream>
using namespace std;

int main()
{
    freopen("ANS.OUT",  "wt", stdout);
    //1 nguoi : 1
    //2 nguoi : 365/366 (khac 1 nguoi) //xac suat khac ngay sinh
    //3 nguoi: 364/366 * 365/366
    //4 nguoi : 363/366* 364/366 * 365/366; 
    
    //Tim n sao cho: 1- f(n)>1/2
    //f(n)<1/2
    int a=1,n=1;

    double april=30.0/366.0, notApril= 1-april;
    double tmp = notApril;
    double xs=0.0;
    
    for( n=2;;n++)
    {       
         xs = 1 - n * tmp* april;
         tmp *=  notApril;
         xs -= tmp;
         cout<<n<<" "<<xs<<endl;
         if(xs> 0.5) {
                cout<<"Result: "<<n<<" "<<xs<<endl; return 0;
        }
    }
     
        
}
