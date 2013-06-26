#include <stdio.h>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void calc(int a, int b);

int main()
{
	int n;
	int a,b;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		calc(a,b);
	}
}
void  calc(int a, int b){
	stringstream ss;
	string sa,sb;
	ss<<a;
	ss>>sa;
	ss.clear();
	ss<<b;
	ss>>sb;
	//Dao nguoc sa,sb
	int i,j,tmp;
	i=0;j=sa.length()-1;
	while(i<j){
		tmp=sa[i];
		sa[i]=sa[j];
		sa[j]=tmp;
		i++;j--;
	}
	i=0;j=sb.length()-1;
	while(i<j){
		tmp=sb[i];
		sb[i]=sb[j];
		sb[j]=tmp;
		i++;j--;
	}
	ss.clear();
	ss<<sa;
	ss>>a;
	ss.clear();
	ss<<sb;
	ss>>b;
	int c=a+b;
	ss.clear();
	string sc;
	ss<<c;
	ss>>sc;
	i=0;j=sc.length()-1;
		while(i<j){
			tmp=sc[i];
			sc[i]=sc[j];
			sc[j]=tmp;
			i++;j--;
		}
	ss.clear();
	ss<<sc;
	ss>>c;
	cout<<c<<endl;


}
