#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define DOWN(i,a,b) for(int i=a;i>=b;--i)

int main()
{
    //freopen("CPPSET.IN", "rt", stdin);
    //freopen("CPPSET.OUT", "wt", stdout);
    int cmd,res;
    set<int> s;
    set<int,greater<int> > s2;
    set <int>::iterator it, ilow, ihig, item;
    int x;
    while(true)
    {
        //cin>>cmd;
        scanf("%d",&cmd);
        if(cmd==0) break;
        switch(cmd)
        {   
            //cout<<" lenh: " <<cmd<<endl;
            case 1:
                scanf("%d",&x);
                s2.insert(x);
                s.insert(x); break; //add
            case 2:
                scanf("%d",&x);
                it=s.find(x);
                if(it!=s.end()) //ton tai
                {
                    s.erase(it);
                    s2.erase(s2.find(x));
                }
                break; //delete
            case 3: 
                {
                    if(s.empty()) printf("empty\n");
                    else
                    printf("%d\n",*(s.begin()));           
                }
                break; //miminum
            case 4: 
                if(s.empty()) printf("empty\n");
                else
                {
                    res=*(s2.begin());
                    printf("%d\n",res);
                }
                break; //maxi
            case 5:
                scanf("%d",&x);
                if(s.empty()) printf("empty\n");
                it=s.lower_bound(x+1);
                if(it==s.end())
                {
                    printf("no\n");    
                }
                else 
                    printf("%d\n",*it);
                
                 break; //succ x, nho nhat lon  x                                  
            case 6: 
                scanf("%d",&x);
                if(s.empty()) printf("empty\n");
                it=s.lower_bound(x);
                if(it==s.end())
                {
                    printf("no\n");    
                }
                else 
                    printf("%d\n",*it);
                break;  //succ2 x: nho nhat ko nho hon x           
            case 7:
                scanf("%d",&x);
                if(s2.empty()) printf("empty\n");
                it=s2.lower_bound(x-1);
                if(it==s2.end())
                {
                    printf("no\n");    
                }
                else 
                    printf("%d\n",*it);
                break; ///pred x : tim so lon nhat nho hon x
            case 8:
                scanf("%d",&x);
                if(s2.empty()) printf("empty\n");
                it=s2.lower_bound(x);
                if(it==s2.end())
                {
                    printf("no\n");    
                }
                else 
                    printf("%d\n",*it);
                break; // pred_2 x: tim so lon nhat ko qua x                   
        
        }
    }
    
}

