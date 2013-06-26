#include <iostream>
using namespace std;
#include <stack>
#include <string.h>
#include <conio.h>
#include <math.h>

stack <string> st;
//char s[]="((()(()((())))";
char s[]="(((()((()))(()()()()()()()()))))";

int main()
{
 int i=0;
 int num=0;
 int len=strlen(s);
 while(i<len)
 {
  if(s[i]=='(') {
                st.push(s[i]);
                i++;
                continue;
                }
  if(s[i]==')')
  {     int tmp=0;       
        while(s[i]==')')
        {
         int num=0;
         while(st.front()!='(')
         {
           tmp=st.front();
         }               
         st.pop();
         tmp++;
         i++;                
        }
        st.push(tmp);    
  }                  
 }
 if(!st.empty()) cout<<"Xau khong hop le!"<<endl;
 else cout<<"Depth= "<<num<<endl;
 getch();    
}
int toInt(string a)
{
     
}
