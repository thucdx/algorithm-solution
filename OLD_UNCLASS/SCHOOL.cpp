#include <iostream>
#include <vector>
#include <cstring>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define INF 10000000
// Thuat toan 3*n^2 +n
using namespace std;
struct edge{
       int v;//next or prev vertice
       int a; // travel on foot
       int b;//by car
       void operator=(edge e)
       {
         v=e.v;
         a=e.a;
         b=e.b;
       }
};
vector <edge> nxt[10005];
vector <edge> prv[10005];
int fromHouse[10005];
int toSchool[10005];
int toOffice[10005];

int minTime;
int n,k,m;
void findFromHouse();
void findToSchool();
void findToOffice();
void calc();

int main()
{
    freopen("input.txt","rt", stdin);
    freopen("output.txt","wt", stdout);
    
    cin>>n>>m>>k;
    int i,j,_a,_b;
    FOR(s,1,m)
    {
     cin>>i>>j>>_a>>_b;
     edge tNext,tPrev;
     tNext.v=j;
     tNext.a=_a;
     tNext.b=_b;
     tPrev.v=i;
     tPrev.a=_a;
     tPrev.b=_b;
     nxt[i].push_back(tNext);
     prv[j].push_back(tPrev);
     //cout<<i<<" "<<nxt[i].front().v<<' '<<nxt[i].front().a<<' '<<nxt[i].front().b<<endl;
    }
    findFromHouse();
    findToSchool();
    findToOffice();
    calc();
    cout<<minTime;                          
}
void calc()
{    minTime=INF;
    FOR(i,1,n)
    {
        if(fromHouse[i]+toSchool[i] <=59) //co the den truong
        {
         if(fromHouse[i]+toOffice[i]<=minTime)
         {
               minTime=fromHouse[i]+toOffice[i];
         }
        }       
    }  
}
void findFromHouse()  //tim duong di ngan nhat toi tat ca cac dinh trong do thi.
{     
      bool flag[10005];
      memset(flag,0,n+1);
      FOR(i,1,n)
               fromHouse[i]=INF;
      fromHouse[1]=0;
      flag[1]=true;
      int nVer=1; //dung khi nVer=n;
      int newVer=1;
      vector<edge>::iterator iter;
      edge e;
      do
      {
        //tim tat ca next voi  newVer;
        for(iter=nxt[newVer].begin();iter!=nxt[newVer].end();iter++)
        {
            e=*iter;
            if(!flag[e.v])
            {
             fromHouse[e.v]=min(e.b+fromHouse[newVer],fromHouse[e.v]);                                                                                                                   
            }
        }
        //tim min;
        int minDis=INF,pos=-1;;
        FOR(i,1,n)
        {
            if (!flag[i]) //chua duoc chon moi xet
            {
                if(fromHouse[i]<minDis)
                {
                 minDis=fromHouse[i];
                 pos=i;
                }         
            }      
        }
        //chon
        if(pos==-1) break; //khong tim duoc=> het lien thong.
        newVer=pos;
        //cout<<"Chon "<<pos<<" "<<fromHouse[pos]<<endl;
        flag[newVer]=true;
        nVer++;     
      }
      while(nVer<=n);
}
void findToSchool()
{
     bool flag[10005];
     memset(flag,0,n+1);
      FOR(i,1,n)
               toSchool[i]=INF;
      toSchool[k]=0;
      flag[k]=true;
      int nVer=1; //dung khi nVer=n;
      int newVer=k;
      vector<edge>::iterator iter;
      edge e;
      do
      {
        //tim tat ca next voi  newVer;
        for(iter=prv[newVer].begin();iter!=prv[newVer].end();iter++)
        {
            e=*iter;
            if(!flag[e.v])
            {
             toSchool[e.v]=min(e.a+toSchool[newVer],toSchool[e.v]);//di bo                                                                                                                   
            }
        }
        //tim min;
        int minDis=INF,pos=-1;;
        FOR(i,1,n)
        {
            if (!flag[i]) //chua duoc chon moi xet
            {
                if(toSchool[i]<minDis)
                {
                 minDis=toSchool[i];
                 pos=i;
                }         
            }      
        }
        //chon
        if(pos==-1) break; //khong tim duoc=> het lien thong.
        newVer=pos;
        //cout<<"Chon "<<pos<<" "<<fromHouse[pos]<<endl;
        flag[newVer]=true;
        nVer++;     
      }
      while(nVer<=n);
      
}
void findToOffice()
{
     bool flag[10005];
     memset(flag,0,n+1);
      FOR(i,1,n)
               toOffice[i]=INF;
      toOffice[n]=0;
      flag[n]=true;
      int nVer=1; //dung khi nVer=n;
      int newVer=n;
      vector<edge>::iterator iter;
      edge e;
      do
      {
        //tim tat ca next voi  newVer;
        for(iter=prv[newVer].begin();iter!=prv[newVer].end();iter++)
        {
            e=*iter;
            if(!flag[e.v])
            {
             toOffice[e.v]=min(e.b+toOffice[newVer],toOffice[e.v]);//by car                                                                                                                  
            }
        }
        //tim min;
        int minDis=INF,pos=-1;;
        FOR(i,1,n)
        {
            if (!flag[i]) //chua duoc chon moi xet
            {
                if(toSchool[i]<minDis)
                {
                 minDis=toOffice[i];
                 pos=i;
                }         
            }      
        }
        //chon
        if(pos==-1) break; //khong tim duoc=> het lien thong.
        newVer=pos;
        //cout<<"Chon "<<pos<<" "<<fromHouse[pos]<<endl;
        flag[newVer]=true;
        nVer++;     
      }
      while(nVer<=n); 
}
