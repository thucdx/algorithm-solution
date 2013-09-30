#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define REMAIN 1337377
using namespace std;
struct Node{
    int words;
    int prefixes;
    Node* next[256];
    Node() {
        words=0;
        prefixes=0;
        REP(i,0,255)
            next[i]=NULL;
    }
} r;
void add(string word);
int countWord(string word);
int countPrefixes(string prefix);

int f[300005];
string str,p;
int n;
int main()
{
    //freopen("NKSEV.IN","rt", stdin);
    cin>>str;
    scanf("%d",&n);
    int maxLength=0;
    int len=str.length();
    REP(i,1,n)
    {
        cin>>p;
        maxLength=max(maxLength,(int)p.length());
        add(p);    
    }
    //Solve
    f[0]=countWord(str.substr(0,1));
    string _st;
    for(int i=1;i<len;++i)
    {
        for(int j=0;j<min(i+1,maxLength);j++)
        {
            _st=str.substr(i-j,j+1);
            //cout<<"_st    "<<_st<<endl;
            if(countWord(_st)!=0)
            {   if(i>j)
                    f[i]=(f[i]+f[i-j-1])%REMAIN;     
                else f[i]=(f[i]+1)% REMAIN;
            }
        }   
    }
    cout<<f[len-1];
}
void add(string word)
{
    Node* cur;
    cur=&r;
    int len=word.length();
    REP(i,0,len-1)
    {
        if(cur->next[word[i]]==NULL)
        {
            Node* a=new Node();
            cur->next[word[i]]=a;
        }
        cur=cur->next[word[i]];
        cur->prefixes++;      
        if(i==len-1) cur->words++;   
    } 
}
int countWord(string word)
{
    Node* cur;
    cur=&r;
    int len=word.length();
    REP(i,0,len-1)
    {
        if(cur->next[word[i]]==NULL)
        {
            return 0;
        }
        cur=cur->next[word[i]];
        if(i==len-1) return cur->words; 
    } 
    return 0;         
}
int countPrefixes(string prefix)
{
    Node* cur;
    cur=&r;
    int len=prefix.length();
    REP(i,0,len-1)
    {
        if(cur->next[prefix[i]]==NULL)
        {
            return 0;
        }
        cur=cur->next[prefix[i]];
        if(i==len-1) return cur->prefixes; 
    } 
    return 0;
    
        
}
