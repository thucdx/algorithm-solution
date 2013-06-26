#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)

struct big{
       vector<int> digits;
       int get(int d)const {
           return d<(int)digits.size()? digits[d]:0;
       } 
       void set(int d,int x){
           if(d>=(int)digits.size()) digits.resize(d+1,0);
           digits[d]=x;
       }
       big(){}
       big(int x){
           while(x){
               digits.push_back(x%10);
               x/=10;
           }
       }
       big operator + (const big &b)const{
           int c=0;
           big o;
           for(int i=0;c||i<(int)digits.size()||i<(int)b.digits.size();i++){
               c+=get(i)+b.get(i);
               o.set(i,c%10);
               c/=10;
           }    
           return o;
       }
       big operator - (const big &b)const{
           big o;
           int c=0;
           int temp;
           for(int i=0;i<(int)digits.size();i++){
               temp=get(i)-b.get(i)-c;
               if(temp<0){
                   o.set(i,temp+10);
                   c=1;
               }
               else{
                   o.set(i,temp);
                   c=0;
               }
           }
           return o;
       }
       string tostr()const{
           if(digits.empty()) return "";
           string o;
           for(int d=digits.size()-1;d>=0;d--) o+='0'+digits[d];
           return o;
       }
       void out()const{
           int i=digits.size()-1; 
           while(digits[i]==0) i--;
           while(i>=0) printf("%d",digits[i--]);
       }
};
big f[125][125];
string s;
void exe();
int main()
{   
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    cin>>s;
    exe();
    f[0][s.length()-1].out();
    //system("pause");
}
void exe()
{
     int len=s.length();
     /*
     FOR(i,0,len-1)
     FOR(j,0,len-1)
          f[i][j]=big(0);
          */
     FOR(i,0,len-1) f[i][i]=big(1);
     
     FOR(i,0,len-1)
     FORD(j,i-1,0)
     { //tinh f[j][i], tinh tu j toi i
     /*
       f[j][i]=big(1)+f[j][i-1] ;//khong xau nao chua s[i]
       FOR(t,j,i-1)
       {
        if(s[t]==s[i])
        {
         f[j][i]=f[j][i]+f[t+1][i-1]+big(1);
        }
        }
     }
     */
          f[j][i]=f[j+1][i]+f[j][i-1];
          if(s[j]==s[i]) f[j][i]=f[j][i]+big(1);
          else 
          {
           f[j][i]=f[j][i]-f[j+1][i-1];                         
          }
     }
}
