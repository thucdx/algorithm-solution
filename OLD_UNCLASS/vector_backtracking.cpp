/*
Trong ma(.t pha(?ng to.a ?o^. có N véc to+. Mo^~i mo^.t véc to+ ?u+o+.c cho bo+?i hai chi? so^' x và y. To^?ng cu?a hai véc to+ (xi, yi) và (xj, yj) ?u+o+.c ?i.nh nghi~a là mo^.t véc to+ (xi + xj, yi + yj). Bài toán ?a(.t ra là ca^`n cho.n mo^.t so^' véc to+ trong N véc to+ ?ã cho sao cho to^?ng cu?a các vec to+ ?ó là véc to+ (U, V).

Yêu ca^`u: ?e^'m so^' cách cho.n thoa? mãn yêu ca^`u bài toán ?a(.t ra o+? trên.
Input

Dòng thu+' nha^'t ghi so^' N (0 ? N ? 30).

N dòng tie^'p theo, dòng thu+' i ghi các so^' nguyên xi, yi la^`n lu+o+.t là hai chi? so^' cu?a véc to+ thu+' i. (|xi|, |yi| ? 100).

Dòng cuo^'i cùng ghi so^' hai so^' nguyên U V (|U|, |V| ? 109).
Output

Go^`m mo^.t so^' duy nha^'t là so^' cách cho.n thoa? mãn.
Example

Input:
4
0  0
-1  2
2  5
3  3
2  5

Output:
4

*/
#include <iostream>
using namespace std;
#include <conio.h>
#define MAX 40

int listX[MAX];
int listY[MAX];
int n;
int sumX,sumY;
int sl=0;
int currentSumX=0,currentSumY=0;
void swap(int x, int y){
     int temp;
     temp= listX[x];
     listX[x]=listX[y];
     listX[y]=temp;
     temp= listY[x];
     listY[x]=listY[y];
     listY[y]=temp;
}
void quicksort(int start, int end){
     int k,key,i,j;
     if(start>=end ) return;
     //start <end;
     k=(start+end)/2;
     key=listX[k];
     swap(start, k);
     i=start+1;
     j=end;
     while(i<=j){
                 while(i<=end && listX[i]<=key)
                 i++;
                 while(j>=start+1&&listX[j]>key)
                 j--;
                 if(i<j) swap(i,j);
                 
     }
     swap(start,j);
     quicksort(start,j-1);
     quicksort(j+1,end);
}

void attempt(int i){
     int j;
     for(j=i+1;j<n;j++)
     {
      if (currentSumX+listX[j]==sumX ) {
                                    if(currentSumY+listY[j]==sumY)
                                    sl++;
         }
         else {
              //(sumX< currentSumX && listX[j]>=0) return;
              //(sumX> currentSumX+(n-j+1)*listX[n-1] &&listX[j]>=0) return;
              currentSumX+=listX[j];
              currentSumY+=listY[j];
              attempt(j);
              currentSumX=currentSumX-listX[j];
              currentSumY=currentSumY-listY[j];
              }                
     }
}
int main(){
    int i=0;
    //Input
    cin>>n;
    for(i=0;i<n;i++){
                      cin >>listX[i];
                      cin >>listY[i];
                       }
    cin >>sumX>>sumY;
    
    //process
    //printlistX(listX,n);
    quicksort(0,n-1);
   
    //printlistX(listX,n);
    attempt(-1);
    cout<<sl;
    getch();
}
