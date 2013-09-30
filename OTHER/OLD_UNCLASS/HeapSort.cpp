/*
  Name: Heap Sort
  Copyright: Dinh Xuan Thuc
  Author: noname
  Date: 03/06/11 22:07
  Description: Heap sort using C++
*/

#include <iostream>
using namespace std;
#include <conio.h>

int arr[]={111,-1,15,65,68,60,49,366,13,3566,34};

void makeHeap(int arr[],int n);
void headToList(int arr[],int n);
void heapSort(int arr[],int n); //after make Heap
void display(int arr[],int n);
int main()
{
    heapSort(arr,11);
    getch();
}

void display(int arr[], int n)
{
     for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
     cout<<endl;     
}
void makeHeap(int a[],int n)
/*
Make arr to heap
*/
{
     int i,j,x,s,f;
     
     for(i=1;i<n;i++)
     { x=a[i];
       s=i;
       while(s>0 && x>a[(s-1)/2])
       {
        a[s]=a[(s-1)/2];
        s=(s-1)/2;   
       }
       a[s]=x;              
     }
     display(a,n);
     
}
void headToList(int a[], int n)
{
     int i,f,s;
     int x;
     for(i=n-1;i>0;i--)
     {
         x=a[i];a[i]=a[0];
         f=0;
         s=2*f+1;
         if(s+1<i && (a[s]<a[s+1])) s++; //chon Right Child neu Right Child>Left Child
         while(s<i && x<a[s])
         {
              a[f]=a[s];
              f=s;
              s=2*f+1;
              if((s+1)<i && a[s]<a[s+1]) s++;          
         }
         a[f]=x;                                       
     }              
}
void heapSort(int a[], int n)
{
     makeHeap(a,n);
     headToList(a,n);
     display(a,n);          
}
