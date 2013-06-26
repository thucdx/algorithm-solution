#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{

	int nTest,n,i,j,mu;
	cin>>nTest;

	for(i=1;i<=nTest;i++){
		cin>>n;
		mu=5;j=0;
		while(mu<=n){
			j+=n/mu;
			mu*=5;
		}
		cout<<j<<endl;
	}
}
