
#include <iostream>
#include <stdio.h>
using namespace std;
int n,k;
int s[18];
int l1,l2;
int list[18];
int head[25001];
int tail[25001];
bool f[18];
long long num;
void input();
void att(int );
void attOp1(int);
void attOp2(int);
int main() {
	input();
	if(n<=10){
		att(1);
	}
	else{
		l1=n/2;
		l2=l1+1;
		attOp1(1);
		list[l2-1]=36000;
		attOp2(l2);

	}
	cout<<num<<endl;
	//printf("%lld\n",num);
}
void input(){
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		f[i]=true;
		scanf("%d",&s[i]);
		//cout<<s[i]<<endl;
	}
	for(i=0;i<=25000;i++)
		head[i]=tail[i]=0;
	list[0]=35000;
}
void att(int i) {
	int j;
	int dis;
	if(i==(n+1)) {
		num++;
		return ;
	}
	for(j=1;j<=n;j++){
		if(f[j])//s[j] chua duoc tron trong day.
		{
			dis=s[j]-list[i-1];
			if(dis<0)dis=-dis;
			if(dis<=k)
				continue;
			f[j]=false;
			list[i]=s[j];
			att(i+1);
			f[j]=true;
		}
	}
}
void attOp1(int) {
	int i,j;
	int dis;
	if(i==l1+1) {
		tail[list[i-1]]++;
		return ;
	}
	for(j=1;j<=l1;j++){
		if(f[j])//s[j] chua duoc tron trong day.
		{
			dis=s[j]-list[i-1];
			if(dis<0)dis=-dis;
			if(dis<=k)
				continue;
			f[j]=false;
			list[i]=s[j];
			att(i+1);
			f[j]=true;
		}
	}
}
void attOp2(int i) {
	int j;
	int dis;
	if(i==n+1) {
		head[list[1]]++;
		return ;
	}
	for(j=l2;j<=n;j++){
		if(f[j])//s[j] chua duoc tron trong day.
		{
			dis=s[j]-list[i-1];
			if(dis<0)dis=-dis;
			if(dis<=k)
				continue;
			f[j]=false;
			list[i]=s[j];
			att(i+1);
			f[j]=true;
		}
	}
}


