// Nguyen Dinh Tu


#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    //freopen("output.txt","wt", stdout);
    /*
    string rs;
    for(int i=1;i<=29;i++)
        rs+=rand()%27+'a';
    int i,j;
    for(int i=0;i<12;i++){
        rs[i*i%29]=s[i];
    }
    
    cout<<rs<<endl;
    cin>>i;
    
    
    */
    
    
    
    
    
    string s="nglbuundzymvgtsneqwbiyzhxntse";
    for(int i=0;i<((s.length()-5)>>1);++i)
        cout<<s[i*i%s.length()];  
        
        
        
        
        
        
        
        
        
        
        
        
          
    cin>>s;
}
