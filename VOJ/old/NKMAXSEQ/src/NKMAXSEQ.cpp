//============================================================================
// Name        : NKMAXSEQ.cpp
// Author      : ThucDX
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <algorithm>
#include <climits>
#include <stdio.h>
struct Node{
	long long val;
	int pos;
};
int n,p,result=-1;
long long l[50005];
Node s[50005];
int cmp(const void *a, const void *b){
	Node *ia=(Node *)a, *ib=(Node *)b;
	return (ia->val-ib->val);
}
int main() {
	int i,head,tail,mid,pos;
	long long value;
	scanf("%d%d",&n,&p);
	l[0]=0;
	for(i=1;i<=n;++i){
		cin>>value;
		l[i]=l[i-1]+value;
		s[i].val=l[i];
		s[i].pos=i;
	}
	s[0].val=-25000000000LL;
	s[0].pos=0;
	qsort(s,n+1,sizeof(s[0]),cmp);
	for(i=1;i<=n;++i)
		if(s[i].pos>s[i-1].pos) s[i].pos=s[i-1].pos;
	for(i=1;i<=n;++i){
			value=l[i]-p;
			head=1;
			tail=n;
			//tim kiem gia tri lon nhat, nho hon value.
			while(tail-head>1){
				mid=(tail+head)/2; //2
				if(s[mid].val <=value) head=mid;
				else tail=mid-1;
			}
			if(s[head].val<=value) pos=head;
			else if(s[tail].val<=value) pos=tail;
			else pos=-1;
			if(pos!=-1)
			if(s[pos].pos<i)
				if(i-s[pos].pos>result) result=i-s[pos].pos;
	}
	cout<<result<<endl;

}
