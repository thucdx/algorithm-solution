#include <iostream>
using namespace std;
#define max 501
#include <conio.h>
int n;
int cb[max][max];
//int r[max][max][max];
int L[max][max];
int R[max][max];
int q;
void process();
int main()
{
    int i,j;
    int a,b;
    int xa,ya,xb,yb;
    //cin>>n;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
     cin>>cb[i][j];
     if((i+j)%2==1) cb[i][j]=-cb[i][j];                
    }
    process();
    cin>>q;
    for(i=1;i<=q;i++)
    {
       cin>>xa>>ya>>xb>>yb;               
       xa--;
       ya--;
       xb--;
       yb--;
       //Tinh
       int sum=0;
       for(j=xa;j<=xb;j++)
       {
        
        sum+= (L[j][n-1]-(L[j][ya]- cb[j][ya] +R[j][yb]- cb[j][yb]));
       }
       if(sum<0) sum=-sum;
       cout<<sum<<endl;
    }
    
    getch();
}
void process()
{
        int rs=0;
		int sum=0;
		 int i,j,t;
		 for(i=0;i<n;i++)
		 {
		  //Left	 
	      L[i][0]=cb[i][0];
		  for(j=1;j<n;j++)
			  L[i][j]=L[i][j-1]+cb[i][j];
		  //Right
		  R[i][n-1]= cb[i][n-1];
		  for(j=n-2;j>=0;j--)
			  R[i][j]=R[i][j+1]+cb[i][j];
		 }
}
 

