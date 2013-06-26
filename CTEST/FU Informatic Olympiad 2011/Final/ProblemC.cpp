#include <iostream>
using namespace std;
#include <conio.h>
char name[1000][24];
int km[1000];
int minute[1000];
int start,end;
char depart[24], dest[24];
int hour,minstart;
double money=0;
int curKm=0, curTimeH=0,curTimeM=0;

void calc();
bool isPassNight(int hour, int min, int numberOfminute);
double byKm(int m);
int main()
{
  int i=0;
    while(true)
  {
  cin>>name[i];
  if( strcmp(name[i],"$")==0) break;
  cin >>km[i];
  cin>>minute[i];           
  i++;
  }
  cin>>depart>>dest;
  scanf("%d:%d",&hour,&minstart);
  // start, end;
  int k=0;
  for( k=0;k<i;k++)
       if(strcmp(name[k],depart)==0) {start=k; break;}
  for(int m=k;m<i;m++)
       if(strcmp(name[m],dest)==0) {end=m; break;}
  //Xong
  for(int m=start;m<=end;m++)
   cout<<name[m]<<" "<<km[m]<<" "<<minute[m]<<endl;
   cout<<"!!!!!"<<endl;
   curTimeH=hour;
   curTimeM=minstart;
   calc();
  getch();  
}
double byKm(int m){
       if(1<=m && m<=10) return 1000;
       if(11<=m && m<=30) return 250;
       if(30<m) return 100;
}
bool isPassNight(int hour, int min, int nMin)
{
        int newH=0,newM=0;
        
        if (nMin >= 1440){
                 return true;
                 cout << 'a' << endl;
        }
        newH=(hour+(min+nMin)/60)%24;
        newM=(nMin+min)%60;
        
        if(0<hour && hour<6){ return true; cout << 'b' << endl;}
        if(0<newH && newH<6) { return true; cout << 'c' << endl;}
        /*if (hour >6 && newH>6) return false;
        if(hour==0 && min>=0) return true;
        if(newH==6 && newM==0) return true;
        if(hour*60+min >newH*60+newM) return true;*/
        if(hour*60+min>newH*60+newM)
            { return true; cout << 'd' << endl;}
        return false;       
}
void calc(){
      //init
     money=0;
     curKm=0; curTimeH=0;curTimeM=0;
      //For
     int i,j;
     for(i=start;i<=end;i++)
     {
     for(j=1;j<=km[i];j++)
     {
       
       curKm++;
       money+=byKm(curKm);
       cout<<i<<"Tien---- khi tinh time:"<<money<<endl;
       if(isPassNight(curTimeH,curTimeM,minute[i])) //neu qua dem       addMoney=addMoney*1.2;
           money+=byKm(curKm)*0.2;
       else
        cout << "Ko qua dem" << endl;
       //update
       //curKm++;
       curTimeH=(curTimeH+minute[i]/60+(curTimeM+minute[i])/60)%24;
       curTimeM=(curTimeM+minute[i])%60;
       cout<<"Tiem sau khi tinh time:" <<money<<endl;
     }
     cout<<i<<money<<endl;
     }
     int sumKm=0,sumMin=0;
     for(int i=start;i<=end;i++)
     {
              sumKm+=km[i];
              sumMin+=km[i]*minute[i];
     }
     if(sumKm <sumMin*30) money=money*1.1;
     cout<<money;
}

