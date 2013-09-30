#include<cstdio>
int main(){int a,b;scanf("%d%d",&a,&b);a-=b;printf("%d",a!=0?2*(a>0)-1:0);}
                                                        //(a!=0?(a>0?1:-1):0)
