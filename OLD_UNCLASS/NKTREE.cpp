#include <iostream>
using namespace std;
#define MAX 50000

int n=0;
struct Node{
    int info;
    int l;
    int r;
}list[MAX];
void initial();
bool add(int a);
int main()
{
    int a;
    bool kq=true;
    initial();
    scanf("%d",&a);
    list[0].info=a;
    while(scanf("%d",&a)){
          if(a==-1) break;
          n++;
          if(kq)
          {

            bool c=add(a);
            if(!c)
             kq=false;
           }
    }
    if(kq)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
void initial(){
    int i;
    for(i=0;i<MAX;i++)
    {list[i].l=-1;list[i].r=-1;}
}
bool add(int a){
    int ind=0; //start from Root
    int prev=-1;
    while(ind!=-1){
        prev=ind;
        if(list[ind].info<a)
            ind=list[ind].r;
        else ind=list[ind].l;
    }
    if(prev!=n-1) //khong dung thu tu
        return false;
    else{
        list[n].info=a;
        if(list[prev].info<a)
        {
            list[prev].r=n;
        }
        else list[prev].l=n;
    }
    return true;
}
