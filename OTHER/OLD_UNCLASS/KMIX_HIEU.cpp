#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<iterator>
#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
//#include<conio.h>
#define oo 1111111111
#define nmax 100111
#define MAX 222

using namespace std;

struct point{
     int x,y;
     bool operator == (point D) const{
          return (x == D.x && y == D.y);       
     }
};

point  a[nmax],p;
int n,m,N;

long long kc(point a,point b){
      long long X = (b.x-a.x);
      long long Y = (b.y-a.y);
      return X*X+Y*Y;
}

bool behon(point a,point b,point bn){
      long long ax,ay,bx,by;
      ax = a.x - bn.x;
      ay = a.y - bn.y;
      bx = b.x - bn.x;
      by = b.y - bn.y;
      if(ay!=0 && by==0) return true;
      if(ay==0||by==0) return false;
      return ax*by>ay*bx;
}

void Sort(point a[],int l,int r){
      int i = l,j = r;
      point mid = a[(l+r)/2];
      while(i<j){
           while(behon(a[i],mid,a[0])) i++;
           while(behon(mid,a[j],a[0])) j--;
           if(i<=j) swap(a[i++],a[j--]);
      }
      if(i<r) Sort(a,i,r);
      if(l<j) Sort(a,l,j);
}

int ccw(point p1,point p2,point p3){
      long long a1,a2,b1,b2,t;
      a1 = p2.x-p1.x;
      a2 = p3.x-p1.x;
      b1 = p2.y-p1.y;
      b2 = p3.y-p1.y;
      t = a1*b2-a2*b1;
      if(t==0) return 0;
      if(t>0) return 1;
      return -1;
}

int graham(point a[],int n){
      int m = 1;
      for(int i = 2;i<=n;i++)
           if(a[m].y>a[i].y) m = i;
      for(int i = 1;i<=n;i++)
           if(a[i].y==a[m].y && a[i].x>a[m].x) 
                m = i;
      swap(a[1],a[m]);
      a[0].x = a[1].x;
      a[0].y = a[1].y-1;
      Sort(a,2,n);
      a[++n] = a[1];
      m = 2;
      bool ok = true;
      for(int i = 3;i<=n;i++){
             ok = true;
             while(ccw(a[m],a[m-1],a[i])>=0){
                   if(ccw(a[m],a[m-1],a[1])==0){
                        ok = false;
                        if(kc(a[m],a[m-1])<kc(a[m-1],a[i]))
                              swap(a[m],a[i]);
                        break;      
                   }
                   else m--;    
             }
             if(ok) swap(a[++m],a[i]);
      }
      return --m;  
} 

long long stg(point a,point b,point c){
     long long s = (b.x-a.x)*1LL*(b.y+a.y)+(c.x-b.x)*1LL*(c.y+b.y)+ (a.x-c.x)*1LL*(a.y+c.y);
     return s>0?s:-s; 
}

int thuoc(point a,point b,point c){
               if(ccw(a,b,c)==0 && ((a.y<=c.y && c.y<=b.y)||(a.y>=c.y && c.y>=b.y))) return true;
               else return false;

}

int namtrong(point p,int l,int r,point b[]){
     while(r-l>2){
          int mid = (l+r+1)/2;
          int k = ccw(b[1],b[mid],p);
          if(k==0){
                if((b[1].x-p.x)*(b[mid].x-p.x)<0) return 1;;
                return 0;
          }
          if(k==1) l = mid-1;
          if(k==-1) r = mid;
     }
     point x,y,z;
     x = b[1];
     y = b[r];
     z = b[r-1];
     long long k = stg(x,y,z);
     long long t = stg(x,y,p)+stg(x,z,p)+stg(y,z,p);
     if(t>k) return 0;
     int kk = ccw(x,y,p)*ccw(x,z,p)*ccw(y,z,p);
     if(kk!=0) return 1;
     if(p==x||p==y||p==z) return 0;
     if(r==3){
           if(n<=3) return 0;
           if(ccw(x,y,p)==0)
                 return 1;
     }
     if(r==n &&ccw(x,z,p)==0)
          return 1;
     if(ccw(x,y,p)==0 && r!=n)
           return 1;
     if(ccw(x,z,p)==0 && r!=3)
           return 1;
     return 0;
}

int main(){
     freopen("KMIX.IN", "rt", stdin);    
     freopen("KMIX_HIEU.OUT", "wt", stdout);
     scanf("%d",&N);
     for(int i = 1;i<=N;i++){
          scanf("%d %d",&a[i].x,&a[i].y);
     }   
     
     if(N>=3) n = graham(a,N);
     else n=N;
     if(n==1 && N>=2){
           m = 1;
           for(int i = 2;i<=N;i++)
               if(a[m].y<a[i].y) m = i;
           a[2] = a[m];
           n = 2;
     }
     //printf("%d %d\n",n,m);
     scanf("%d",&m);
     for(int i = 1;i<=m;i++){
          scanf("%d %d",&p.x,&p.y);
          if(n==1){
               if(a[1]==p) printf("YES\n");
               else printf("NO\n");
          }
          else if(n==2){
               //printf("%d\n",ccw(a[1],a[2],p));
               if(ccw(a[1],a[2],p)==0 && a[1].y<=p.y && p.y<=a[2].y) printf("YES\n");
               else printf("NO\n");  
          }
          else{
          bool flag = false;
          for(int j = 1;j<n;j++) 
                if(thuoc(a[j],a[j+1],p)) {
                                    flag = true;
                                    break;
          }
          if(thuoc(a[n],a[1],p)) flag = true;
          if(namtrong(p,1,n,a)||flag) printf("YES\n");
          else printf("NO\n");
          }
     }
    // getch();
}

