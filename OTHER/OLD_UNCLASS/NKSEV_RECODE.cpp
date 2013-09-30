#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define DOWN(i,a,b) for(int i=a;i>=b;i--)
#define REMAIN 1337377
//#include <conio.h>
using namespace std;
struct Node{
    int words;
    //int prefixes;
    Node* next[30];
    Node() {
        words=0;
       // prefixes=0;
        REP(i,0,29)
            next[i]=NULL;
    }
} r;
void add(char *s );
int f[300005];
string str;
Node* cur;
char p[105];
int n;
int maxLength=0;
int main()
{
    ///freopen("NKSEV.IN","rt", stdin);
    cin>>str;
    scanf("%d",&n);
    
    int len=str.length();
    REP(i,1,n)
    {
        scanf("%s",p);
        //maxLength=max(maxLength,(int)p.length());
        add(p);    
    }
    //Solve
    //f[0]=countWord(str.substr(0,1));
    string _st;
    for(int i=0;i<len;++i)
    {
        cur=&r;
        for(int j=i;j>=max(0,i-maxLength+1);j--)
        {
            if(cur->next[str[j]-'a']==NULL) break;
            cur=cur->next[str[j]-'a'];
            if(cur->words!=0) 
            {
                if(j>=1)
                    f[i]=(f[i]+f[j-1])% REMAIN;
                else f[i]=(f[i]+1) %REMAIN;
            }   
        }   
    }
    cout<<f[len-1];
   // getch();
}
void add(char *s )
{
    int len=0;
    while(s[len]!='\0') len++;
    if(len>maxLength) maxLength=len;
    cur=&r;
    DOWN(i,len-1,0)
    {
        if(cur->next[s[i]-'a']==NULL)
        {
            Node* a=new Node();
            cur->next[s[i]-'a']=a;
        }
        cur=cur->next[s[i]-'a'];
        //cur->prefixes++;      
        if(i==0) cur->words++;   
    }     
}
