//============================================================================
// Name        : DEMOBIT.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int  n;
	int tmp;
	int i;
	cin>>n;
	for(i=0;i<=10;i++)
	{
		tmp=n;
		cout<<"bit thu "<<i <<" cua "<<n <<"la : "<<(n&(1<<i))<<endl;
		tmp =tmp &~(1<<i);
		cout<<"xoa thu "<<i <<" cua "<<n <<", so moi la : "<<tmp<<endl;
	}

}
