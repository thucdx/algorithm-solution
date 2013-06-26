#include <iostream>
using namespace std;
#include <cstring>

struct player{
    int a,h,pos;
}p[300005];
int num[100005];
int b[100005];
int win[100005];
int n;

int cmp(const void * a, const void * b)
{
    player * _a= (player *) a;
    player *_b= (player *)b;
    if(_a->h > _b->h) return 1;
    if(_a->h < _b->h) return -1;
    if(_a->a > _b->a) return 1;
    if(_a->a < _b->a) return -1;
    return 0;
}
void update(int i)
{
      while(i<= p[n-1].a)
      {
           b[i]++;
           i+=i&(-i); 
      } 
}

int get(int i)
{   
    int rs=0;
       while(i>0)
       {
            rs+=
        } 
}
int main()
{
      scanf("%d",&n);
      for(int i=0;i<n;++i)
      {
        scanf("%d%d",&p[i].a,&p[i].b);     
        p[i].pos=i;
       }
       qsort(p, n,sizeof(p[0]),cmp);
       for(int i=0;i<n;++i)
       {
            update(p[i].a);
            win[p[i].pos]=get(p[i].a-1); //nho hon a
        }
           
}
