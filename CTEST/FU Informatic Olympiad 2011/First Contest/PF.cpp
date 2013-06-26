#include <iostream>
using namespace std;
#include <math.h>
int main(){
    int numberOfTest;
    int n,j,l;
    cin >>numberOfTest;
    for(int i=1;i<=numberOfTest;i++)
    {       int temp;
            cin >>temp;
             cin >>n;
            
             int count=0;
             //tinh toan
             //cout<< (int)sqrt(2.0*n)<<'!';
             for(j=2;j<=sqrt(2*n);j++)
             {
                                      
              if((2*n) % j==0){
                     if(((2*n)/j - (j+1) )%2 ==0) count++;
              }                        
             }
             cout<<i<<' '<<count<<endl;
    }
}
