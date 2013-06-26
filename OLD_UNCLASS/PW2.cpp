#include <iostream>
using namespace std;
#include <string.h>
char cow[1005][1005];
char good[1005][32];
int c,g;
void input();
void process();
bool isContain(char *a, char*b);
void normal(char *a);
int main()
{
    input();
    process();
}
void input()
{
 int i,j;
 scanf("%d %d",&c,&g);
 for(i=0;i<c;++i)
 {
  scanf("%s",cow[i]);
  normal(cow[i]);
  //cout<<cow[i];
  }
 for(i=0;i<g;++i)
 {
  scanf("%s",good[i]);
  normal(good[i]);
  //cout<<good[i];
  }
}
void normal(char *a)
{
 int i;
 int lla=strlen(a);
 for(i=0;i<lla;++i)
 if(a[i]>='A' &&a[i]<='Z') a[i]=a[i]-'A'+'a';     
}
void process()
{
 int i,j;
 int count;
 for(i=0;i<c;++i)
 {     
       count=0;
       for(j=0;j<g;++j)
       if(isContain(cow[i],good[j])) ++count;
       printf("%d\n",count);
 }
}

bool isContain(char *a, char*b)
{
 int i,j;
 int lla=strlen(a), llb=strlen(b);
 for(i=0,j=0;i<lla &&j<llb;)
 {
  if(a[i]==b[j]) {++i;++j;}
  else i++;                        
 }
 if(j==llb)
 return true;
 else return false;     
}








