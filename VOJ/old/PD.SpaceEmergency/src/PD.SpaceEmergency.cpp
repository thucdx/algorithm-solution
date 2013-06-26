#include <iostream>
#include <algorithm>
using namespace std;
int cmp(const void *a, const void *b){
	return(*(int*) a- *(int *)b);
}
int main() {
	int nTest,i,j;
	long long result;
	int l,time,n,c;
	int list[1000001];
	cin>>nTest;
	for(i=1;i<=nTest;i++){
		cout<<"Case #"<<i<<": ";
		cin>>l>>time>>n>>c;
		for(j=0;j<c;++j)
			cin>>list[i];
		//tinh doan dau.
		j=0;
		long long tSum=0;
		while(true){
				tSum+=2*
		}
		qsort(list,c,sizeof(list[0]),cmp);
		//tinh toan


	}
}
