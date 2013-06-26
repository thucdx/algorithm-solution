#include <iostream>
using namespace std;
#include<conio.h>
bool check=true;
int max=0;
bool done(char* str){
        int i=0;
        while(str[i]!=' '){
                        if(str[i]!='B')
                        return false;
                        else
                        i++;
        }
        i++;
        while(str[i]!='\0'){
                            if(str[i]!='G')
                            return false;
                            else i++;
        }
        return true;
}
int find(char a, char *str){
    int rs=0;
    while(str[rs]!='\0'){
                         if(str[rs]==a) return rs;
                         else rs++;
    }
}
char * s(char *str){
     char* rs=new char[strlen(str)];
     strcpy(rs,str);
     int pos=find(' ',str);
 
     rs[pos]=rs[pos+1];
     rs[pos+1]=' ';
     return rs;
     
}
char * S(char *str){
     char* rs=new char[strlen(str)];
     strcpy(rs,str);
     int pos=find(' ',str);
 
     rs[pos]=rs[pos-1];
     rs[pos-1]=' ';
     return rs;
}
char * h(char *str){
     char* rs=new char[strlen(str)];
     strcpy(rs,str);
     int pos=find(' ',str);
     rs[pos]=rs[pos+2];
     rs[pos+2]=' ';
     return rs;
     
}
char * H(char *str){
     char* rs=new char[strlen(str)];
     strcpy(rs,str);
     int pos=find(' ',str);
 
     rs[pos]=rs[pos-2];
     rs[pos-2]=' ';
     return rs;
     
}

void test(char* str, int count,char* keepTrack){
        if(done(str)){
                      check=false;
                      cout << keepTrack;
        }  
        if(!check && (count <= max)){
                  //viet them vao day
                  if(find(' ',str)>0){
                            
                            test(S(str),count+1,strcat(keepTrack,"s"));
                            keepTrack(strlen(keepTrack)-1)='\0';
                  }
                  if(find(' ',str)<strlen(str)-1){
                            test(s(str),count+1,strcat(keepTrack,"S"));
                            keepTrack(strlen(keepTrack)-1)='\0';
                  }
                  if(find(' ',str)<strlen(str)+2){
                            test(h(str),count+1);
                            keepTrack(strlen(keepTrack)-1)='\0';
                  }
                  if(find(' ',str)<strlen(str)-2){
                            test(H(str),count+1);
                            keepTrack(strlen(keepTrack)-1)='\0';
                  }
        }
}

char * make( int a, int b){
     char * rs=new char [a+b+2];
     int i;
     for(i=0;i<a;i++)
     rs[i]='G';
     rs[i]=' ';
     i++;
     for(;i<a+b+1;i++)
     rs[i]='B';
     rs[i]='\0';
     return rs;
     }
int main(){
           int num;
           cin >> num;
           for(int i=0;i<num;i++){
                   int z;
                   int numBoy, numGirl;
                   cin >> z >> numGirl >> numBoy;
                   char* str=make(numGirl,numBoy);
                   max=numGirl*numBoy+numGirl+numBoy;
                   char * keepTrack = new char[max+2];
                   test(str,0,keepTrack);                    
           }
        getch();
}
