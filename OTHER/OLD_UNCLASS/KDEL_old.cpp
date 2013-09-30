#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <sstream>

#define maxx 1000005
int n,k,nPrime;
bool prime[maxx];
int list[maxx];
int len;
string num;
string result;
void init();
void find(int start,int characterToDel );
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt" ,"rt", stdin);
    freopen("output.txt" , "wt", stdout);
    #endif	
    
	cin>>n>>k;
	init();
	find(0,k);
}
void init(){
	memset(prime,1,maxx);
	prime[0]=0;
	prime[1]=0;
	int i;
	string s;
	stringstream ss;
	long long j;
	nPrime=0;
	for(i=2;i<maxx;++i){
		if(prime[i]){
			++nPrime;
			if(nPrime>n) break;
			ss<<i;
			j=(long long)i*i;
			while(j<maxx){
				prime[j]=0;
				j+=i;
			}
		}
	}
	ss>>num;
	len=num.size();
}
void find(int start,int characterToDel )
{
	if(characterToDel==0) {
		for(int i=start;i<len;++i)
			cout<<num[i];
		return;
	}
	if(len-start<=characterToDel) return;
	int i,maxc=num[start],pos=start;

	for(i=start;i<=start+characterToDel;++i){
		if(num[i]>maxc) {maxc=num[i]; pos=i;}
	}
	
	printf("%d",(maxc-'0'));
	find(pos+1,characterToDel-(pos-start));
}





