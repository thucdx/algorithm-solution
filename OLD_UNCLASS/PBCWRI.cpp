#include <iostream>
using namespace std;
#include <conio.h>
char *A=new char[3000];
char *B=new char[3000000];
int i,j;
void input();
void process();
char * sort(char *str);
char * cpy(int i,int l);
int cmp(const void *a, const void *b)
{
 return (*(char*)a-*(char*)b);
}
int main()
{ 
    input();
    process();
    getch();
}
void input()
{
 cin>>A;
 cin>>B;   
 cout<<" "<<B;  
}

void process()
{    
    A=sort(A);
    int count=0;
    int la=strlen(A),lb=strlen(B);
    int i,j;
    for(i=0;i<lb-la;i++)
    {
       if(strcmp(A,cpy(i,la))==0) count++;
    }  
    cout<<count;
}
char * cpy(int i,int l)
{
 char *rs=new char[l+1];
 int j=0;
 for(j=0;j<l;j++)
 rs[j]=B[i+j];
 rs[i+j]='\0';
 rs=sort(rs);
 return rs;     
}
char *sort(char *str)
{
 char *rs=new char[strlen(str)];
 strcpy(rs,str);
 qsort(rs,strlen(rs),sizeof(char),cmp);
 return rs;     
}
