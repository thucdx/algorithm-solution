#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

using namespace std;
int main(){
	freopen("out_rand.txt","wt", stdout);
	srand(time(NULL));
	int n=rand()%1000000+1;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++)
			cout<<rand()%10000+1<<' ';
		cout<<endl;
	}

}
