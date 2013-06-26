#include <iostream>
using namespace std;
#include <string>
#include <conio.h>
char cow[1000][1000];
char good[1000][1000];
int c,g;
void input();
void process();
bool isContain(char *a, char*b);
void normal(char *a);
int main()
{
    input();
    process();
    getch();
}
void input()
{
 int i,j;
 cin>>c>>g;
 for(i=0;i<c;i++)
 {
  cin>>cow[i];
  normal(cow[i]);
  //cout<<cow[i];
  }
 for(i=0;i<g;i++)
 {
  cin>>good[i];
  normal(good[i]);
  //cout<<good[i];
  }
}
void normal(char *a)
{
 int i;
 for(i=0;i<strlen(a);i++)
 if(a[i]>='A' &&a[i]<='Z') a[i]=a[i]-'A'+'a';     
}
void process()
{
 int i,j;
 for(i=0;i<c;i++)
 {     
       int count=0;
       for(j=0;j<g;j++)
       if(isContain(cow[i],good[j])) count++;
       cout<<count<<endl;
 }
}

bool isContain(char *a, char*b)
{
 int i,j;
 for(i=0,j=0;i<strlen(a) &&j<strlen(b);)
 {
  if(a[i]==b[j]) {i++;j++;}
  else i++;                        
 }
 if(j==strlen(b))
 return true;
 else return false;     
}
