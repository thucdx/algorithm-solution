#include <iostream>
#include <algorithm>
using namespace std;
struct bag{
    int w,v; 
    bag operator+(bag b)
    {
        bag _tmp;
        _tmp.w=w+b.w;
        _tmp.v=v+b.v;
        return _tmp;   
    }
    bag operator-(bag b)
    {
        bag _tmp;
        _tmp.w=w-b.w;
        _tmp.v=v-b.v;
        return _tmp;   
    }
    void operator=(bag b)
    {
        w=b.w;
        v=b.v;    
    }
};
bool cmp(bag a, bag b)
{
    if(a.w> b.w) return false;    
    if(a.w< b.w) return true;
    if(a.v>b.v) return false;
    return true;
}
int cmp2(const void * _a, const void * _b)
{   
    bag *a=(bag*)_a;
    bag *b=(bag*)_b;
    
    if(a->w> b->w) return 1;    
    if(a->w< b->w) return -1;
    if(a->v>b->v) return 1;
    return -1;    
}
bag l[1048600],r[1048600],b[41];
int maxVR[1048600];
int n,m;
int nL=0,nR=0;
bag bl,br;
void makeL();
void makeR();
inline void makeMaxVR();
void attL(int i);
void attR(int i);
void sortL(int head, int end);
void sortR(int head, int end);

int main()
{   
    int i;
    freopen("input.txt","rt", stdin);
    freopen("output.txt","wt", stdout);
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&b[i].w,&b[i].v);        
    }           
    makeL();
    makeR();
    makeMaxVR();
    int j=-1;
    int maxV=0;
    for(i=nL-1;i>=0;--i)
    {
        while(j<(nR-1) && (l[i].w+r[j+1].w<=m)) ++j;
        if(j<nR && (l[i].w+r[j].w<=m)&&(l[i].v+maxVR[j] >maxV)) maxV=l[i].v+maxVR[j];
    }
    cout<<maxV;
    return 0;
}

void makeMaxVR()
{
    maxVR[0]=r[0].v;
    for(int i=1;i<nR;++i)
    {
        maxVR[i]=max(maxVR[i-1],r[i].v);    
    }   
}
void makeL()
{   
    bl.w=0;
    bl.v=0;
    attL(0);
    //sort(l,l+nL,cmp);    
    sortL(0,nL-1);
    //qsort(l,nL,sizeof(l[0]),cmp2);
    //for(int i=0;i<nL;i++)
      //  cout<<i<<" "<<l[i].w<<" "<<l[i].v<<endl;  
}
void makeR()
{
    br.w=0;
    br.v=0;
    attR(n/2);
    sortR(0,nR-1);
    //sort(r,r+nR,cmp);  
    //qsort(r,nR,sizeof(r[0]),cmp2);
   // for(int i=0;i<nR;i++)
       // cout<<i<<" "<<r[i].w<<" "<<r[i].v<<endl;
}
void attR(int i)
{
    if(i>=n)
    {
        r[nR]=br;    
        ++nR;
        return ;
    }
    for(int j=0;j<=1;++j)
    {
        br.w+=j*b[i].w;
        br.v+=j*b[i].v;
        if(br.w<=m)
        {
            attR(i+1);    
        }
        br.w-=j*b[i].w;
        br.v-=j*b[i].v;    
    }     
}
void attL(int i)
{
    if(i>=(n/2))
    {
        l[nL]=bl;    
        ++nL;
        return ;
    }
    for(int j=0;j<=1;++j)
    {
        bl.w+=j*b[i].w;
        bl.v+=j*b[i].v;
        if(bl.w<=m)
        {
            attL(i+1);    
        }
        bl.w-=j*b[i].w;
        bl.v-=j*b[i].v;    
    }
}
