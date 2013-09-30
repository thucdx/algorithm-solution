/*
  Name: 
  Copyright: 
  Author: 
  Date: 04/06/11 11:09
  Description: Quy Hoach Dong- Day Con Chuyen Doi Trang Thai
*/
#include<iostream>
using namespace std;
#include <conio.h>

#define MAX 101
int F[MAX][MAX];
char s1[2*MAX];
char s1_t[2*MAX];
char s2[MAX];
int l1,l2;
void insert(char * s,int i, char c)
{
      int len=strlen(s);
      int j;
      j=len;
      s[j+1]='\0';
      while(j!=i)
      {
       s[j]=s[j-1];           
      }
      s[i]=c;
}
void remove(char *s, int i)
{
    int j;
    for(j=i;j<strlen(s)-1;j++)
    {
     s[j]=s[j+1];                        
    } 
    s[j-1]='\0';
}
void replace(char *s , int i, char c)
{
 s[i]=c;     
}
void input()
{
     cin>>s1>>s2;
     cout<<endl<<"s1= "<<s1;
     cout<<endl<<"s2= "<<s2<<endl;     
}
void initial()
{    
     int i;
     l1=strlen(s1);
     l2=strlen(s2);
     strcpy(s1_t,s1);
     F[0][0]=0;
     for(i=1;i<=l1;i++)
        F[i][0]=i; //Del i ki tu
     for(i=1;i<=l2;i++)
        F[0][i]=i; //Insert i ki tu
}
int min(int a, int b, int c)
{
     int  rs=a;
     if(rs>b) rs=b;
     if(rs>c) rs=c;
     return rs;   
}
void optimize()
{
     int i,j;
     for(i=1;i<=l1;i++)
     for(j=1;j<=l2;j++)
     {
         if(s1[i-1]==s2[j-1])
         F[i][j]=F[i-1][j-1];
         else
          //F[i][j] =min (F[i][j-1],F[i-1][j-1],F[i-1][j])+1;   
          F[i][j]=1+min(F[i][j-1],F[i-1][j-1],F[i-1][j]);
     }     
}
void result()
{    
     
     cout<<"\n Number of moves: "<<F[l1][l2]<<endl;
     int i=l1,j=l2;
     for(i=0;i<=l1;i++)
     {   cout<<endl;
         for(j=0;j<=l2;j++)
         {
             cout<<F[i][j]<<" ";              
         }
     }
     cout<<endl;
     i=l1;
     j=l2;
     while(i!=0 ||j!=0)
     {
           if(F[i][j]==F[i-1][j-1])
           { i--;j--;
             continue;
           }
           if(F[i][j]==1+F[i][j-1])
           {
            cout<<"REMOVE("<<i<<","<<s2[j-1]<<")\n";
            //remove(s1_t,i-1);
            //cout<<s1_t<<endl;
            j--; 
            continue;                      
           }    
           if (F[i][j]==1+F[i-1][j-1]){
              cout<<"REPLACE("<<i<<","<<s2[j-1]<<")\n";
              replace(s1_t,i-1,s2[j-1]);
              cout<<s1_t<<endl;
              i--;
              j--;
              continue;
           }
           if(F[i][j]==1+F[i-1][j])
           {
              cout<<"INSERT("<<i<<","<<s1[i-1]<<")\n";
              //insert(s1_t,i-1,s1[i-1]);
              //cout<<s1_t<<endl;
              i--;
              continue;                                                                     
           }
                            
     }    
}
int main()
{
    input();
    initial();
    optimize();
    result();   
    getch(); 
}
