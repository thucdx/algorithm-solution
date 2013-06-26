#include <iostream>
#include <cstring>
#include <math.h>
#include <stdio.h>

using namespace std;
string s[5];
int n;
int nMax;
void att(int i);
void calc();
bool check(int x, int y);
int main(){
	//freopen("input.txt","rt", stdin);
	//freopen("output.txt","wt", stdout);
	int i;


	do
	{
		cin>>n;
		//cout<<n;
		while(getchar()!='\n');
		if (n==0) break;
		for(i=0;i<n;i++)
		{
			//scanf("%s",s[i]);
			cin>>s[i];
			//cout<<s[i]<<endl;
		}
		calc();

	}
	while(true);


}
void calc(){
	nMax=0;
	att(1);
	cout<<nMax<<endl;
}
void att(int i){
	//i:1=> n^2
	int col,row;//dong x, cot y
	if(i==n*n+1)
	{	//dem
		int r,t,count=0;
		for(r=0;r<n;r++)
			for(t=0;t<n;t++)
			{
				if(s[r][t]=='r')
					{
						//cout<<r<<' '<<t<<endl;
						count++;
					}
			}
			if(count>nMax) nMax=count;
		return;
	}
	row=(int) ((i-1)/n);
	col= i-row*n-1;
	//gan rook
	//cout<<i<<' '<<row<< ' '<<col<<endl;
	//thu xem dat o vi tri row, col co duoc ko!
	if(s[row][col]=='X') att(i+1);
	else //ko phai wall;
	{
		s[row][col]='r';
		if(check(row,col))//ok
		{
			att(i+1);
			s[row][col]='.';
		}

		s[row][col]='.';
		att(i+1);
	}

}
bool check(int x, int y){
	//duyet hang;
	int i,j;
	for(j=y-1;j>=0;j--) //sang trai
	{
			if(s[x][j]=='r') return false;
			if(s[x][j]=='X') break;
	}
	for(j=y+1;j<n;j++) //sang phai
	{
			if(s[x][j]=='r') return false;
			if(s[x][j]=='X') break;
	}
	for(i=x-1;i>=0;i--) //sang trai
	{
			if(s[i][y]=='r') return false;
			if(s[i][y]=='X') break;
	}
	for(i=x+1;i<n;i++)
	{
		if(s[i][y]=='r') return false;
		if(s[i][y]=='X') break;
	}
	return true;
}


