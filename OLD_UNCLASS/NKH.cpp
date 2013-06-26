#include <iostream>
using namespace std;
#include <conio.h>

char s1[101];
char s2[101];
char mix[202];
char f[202]; //bool[i]=true =>s1;
bool isOk();
int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",mix);
    int i,j;
    j=0;//j chay tren mix
    //Khoi tao
    for(i=0;i<strlen(mix);i++)
        f[i]='2';

    for(i=0;i<strlen(s1);i++)
    {                        
        while(j<strlen(mix) )
        {   
            if(mix[j]!=s1[i])                
                j++;
            else //mix[j]==s1[i];
            {
             f[j]='1';
             if(!isOk())
             {
              f[j]='2';            
              j++;
             }     
             else 
             {    
                  break; //thoa man
             
             }
            }
        }
        //mix[j]=s1[i];
    }
    for(i=0;i<strlen(mix);i++)
    {
     cout<<f[i];                         
    }
    cout<<endl;
    
    getch();
    
}
bool isOk()
{
      //check s2 la con mix.
      int i,j=0;
      for(i=0;i<strlen(s2);i++)
      {
          while(j<strlen(mix))
          { if(mix[j]!=s2[i] || f[j]=='1')
               j++;                      
             else break;
          }
          if(j==strlen(mix)) break;
      }
      if(i==strlen(s2)) return true;
      else return false;
      
}
