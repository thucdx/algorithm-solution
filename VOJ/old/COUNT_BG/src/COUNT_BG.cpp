//============================================================================
// Name        : COUNT_BG.cpp
// Author      : ThucDX
// Version     :
// Copyright   : COUNTBG
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
int main(){
    int numberOfTest;
    int n,j,l;
    while(scanf("%d",&n)==1)
    {

             int count=0;
             //tinh toan
             //cout<< (int)sqrt(2.0*n)<<'!';
             for(j=2;j<=sqrt(2*n);j++)
             {

              if((2*n) % j==0){
                     if(((2*n)/j - (j+1) )%2 ==0) count++;
              }
             }
             cout<<count<<endl;
    }
}
