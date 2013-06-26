#include <iostream>
#include <stdio.h>
#include <climits>
#include <string.h>
using namespace std;
string p,t;
int next[10000];
void findNext();
void find();
int main()
{
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	cin>>p>>t;
	cout<<p<<endl<<t<<endl;
	findNext();
	find();
}
void findNext(){
	int i,j;
	next[0]=-1;
	i=0;j=-1;
	while(i<p.length()){
		while((j==-1) || (i<p.length()&& p[i]==p[j])){
			i++;
			j++;
			if(p[i]!=p[j])
				next[i]=j;
			else next[i]=next[j];
		}
		j=next[j];
	}
}

void find(){
	int i,j;
	i=j=0;
	while(i<=t.length()-p.length()){
		while(j==-1 || (j<p.length() && t[i]==p[j])){
			i++;
			j++;
			if(j==p.length())
				cout<<"match at"<<i-p.length()<<endl;
		}
		j=next[j];
	}
	//cout<<"No Match"<<endl;
}
