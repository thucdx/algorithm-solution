#include <iostream>
using namespace std;

char * reverse( char *);
int size(char *);
char * fill(char*,int n );
int main(){
    int nTest;
    cin>>nTest;
    for(int i=1;i<=nTest;i++){
            char a[100];
            char b[100];
            for(int i=0;i<100;i++)
            {
                        a[i]='0';b[i]='0';
            }
            cin>>a;
            cin>>b;
            char *nA,*nB;
            nA=reverse(a);
            int sA=size(a),sB=size(b);
            nB=reverse(b);
            char rs[100];
            int max=(sA>sB)?sA:sB;
            int memo=0;
            int i;
            for( i=0;i<max;i++){
                    
                    int sum=0;
                    int r,s;
                    if(i>sA) r=0; else r=nA[i]-'0';
                    if(i>sB) s=0; else s=nB[i]-'0';
                    sum=r+s+memo;
                    if(sum>=2){
                    rs[i]=sum-2+'0';
                    memo=1;}
                    else {memo=0; rs[i]=sum+'0';}
                    
            }
            if(memo==1) {i++; rs[i]='1';}
            rs[i+1]='\0';
            //xoa 0
            while(rs[i]!='1' && i>=1)
            {
             i--;                 
            }
            rs[i]='\0';
            //print
            for(int j=0;j<i;j++){
                    cout<<rs[i-j-1];
            }
            cout<<"!XOng";
    }
}
char * fill(char * str, int n){
     char*rs= str;
     for(int i=size(str);i<n;i++)
     {
      rs[i]='0';        
     }
     rs[n]='\0';
     return rs;
}
int size(char *str){
    int rs=0;
    while(str[rs]!='\0')
           rs++;
    return rs;             
}
char * reverse(char * str){
     int size=0;
     char result[100];
     while(str[size]!='\0')
          size++;
     for(int i=0;i<size;i++)
             result[i]=str[size-1-i];
     result[size]='\0';
     return result;
          
}
