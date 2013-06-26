//============================================================================
// Name        : MakeFile.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstdlib>
#include <time.h>

int main() {
	srand(time(NULL));
	int c;
	FILE *fout= fopen("C:\\testcase.txt","w");
	int n=1000;
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			c=rand();
			fprintf(fout,"%d",c%2);
			cout<<(c%2);
		}
		//cout<<i<<endl;
		cout<<endl;
		fprintf(fout,"\n");
	}
	fclose(fout);
	cout<<"XONG"<<endl;


}

