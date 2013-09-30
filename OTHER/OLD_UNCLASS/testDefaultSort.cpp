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
#include <algorithm>
#include <vector>
#define MAX 30

int list[MAX];
int n;
int sum;
int sl=0;
int currentSum=0;
void swap(int *x, int *y){
     int temp;
     temp=*x;
     *x=*y;
     *y=temp;
}
void quicksort(int start, int end){
     int k,key,i,j;
     if(start>=end ) return;
     //start <end;
     k=(start+end)/2;
     key=list[k];
     swap(&list[start], &list[k]);
     i=start+1;
     j=end;
     while(i<=j){
                 while(i<=end && list[i]<=key)
                 i++;
                 while(j>=start+1&&list[j]>key)
                 j--;
                 if(i<j) swap(&list[i],&list[j]);
                 
     }
     swap(list[start],list[j]);
     quicksort(start,j-1);
     quicksort(j+1,end);
}
void printList(int arr[],int n)
{
 for(int i=0;i<n;i++)
 printf("%d\t",arr[i]);     
}

void attempt(int i){
     int j;
     for(j=i+1;j<n;j++)
     {
      if (currentSum+list[j]==sum) {
                                   sl++;
         }
         else {
              if(sum< currentSum && list[j]>=0) return;
              if(sum> currentSum+(n-j+1)*list[n-1] &&list[j]>=0) return;
              currentSum+=list[j];
              attempt(j);
              currentSum=currentSum-list[j];
              }                
     }
}
int main(){
    int i=0;
    //Input
    cout<<"n= ";
    cin>>n;
    for(i=0;i<n;i++){
                     cout<<"list["<<i<<"]=";
                     cin >>list[i];
                       }
    cout<<"sum= ";
    cin >>sum;
    //process
    printList(list,n);
    quicksort(0,n-1);
    printf("\n+++++++++\n");
    printList(list,n);
    attempt(-1);
    cout<<"so luong:" <<sl;
    getch();
}
