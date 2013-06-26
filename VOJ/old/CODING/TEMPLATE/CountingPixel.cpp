#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	long long i,j,r;
	long long result;
	do
	{
		cin>>i>>j>>r; //i,j la tam ko quan trong
		if(i==0 && j==0 && r==0) break;
		result=0;
		for(i=0;i<r;++i){
			result+=(sqrt(r*r-i*i-1))+1;
		}
		cout<<(result<<2)<<endl;
	}
	while(true);
}
