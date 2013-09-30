#include <stdio.h>
int main(){
  long unsigned int i,n,m,big;
  long  unsigned int a,b,c,tem;
  freopen("100.in","r",stdin);  
  while(1)  {
    n=scanf("%lu%lu",&a,&b);
    if(n==EOF)
		break;
	printf("%lu %lu ",a,b);
	if(a>b)	{
	  tem=a;
	  a=b;
	  b=tem;
	}
	big=0;
	for(i=a;i<=b;i++)	{
	  c=0;
	  m=i;
	  while(1){
	    if(m==1){
		   	c++;
			break;
		}
		if((m%2)==0)
			m=m/2;
		else
			m=(3*m)+1;

		c++;
	  }
	  if(c>big)
		  big=c;
	}
	printf("%lu\n",big);
  }
  return 0;
}
