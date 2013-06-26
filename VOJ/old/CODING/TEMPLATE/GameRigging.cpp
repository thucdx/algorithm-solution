#include <iostream>
using namespace std;
#include <stdio.h>
#include <cstring>
#include <list>
#include <queue>
//bool g[100005][100005];
list <int> g[100005];
int fr[100005];
bool ok[100005];
int n,k,m;
void traverse(int i);
void BFS(int i);
int main(){
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	do
	{
		cin>>n>>k>>m;
		if(n==0 && k==0 && m==0) break;

		//remove.
		for(int i=1;i<=n;i++)
			g[i].clear();
		memset(ok,0,sizeof(ok));
		for(int i=1;i<=k;i++)
		{
			cin>>fr[i];
			//o	k[fr[i]]=true;
		}
		int a,b;
		for(int i=1;i<=m;i++){
			cin>>a>>b;
			g[a].push_back(b);
		}
		//duyet
		//duyet theo chieu rong tung friend
		int i;
		for(i=1;i<=k;i++){
			BFS(fr[i]);
		}
		bool isOk=true;
		for(i=1;i<=n;i++)
			if(ok[i]==false){ isOk=false;break;}
		if(isOk) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	while(true);
}
void traverse(int i){
	if(ok[i]==true) return;//duyet roi
	cout<<i<<endl;
	ok[i]=true;
	int j;
	//duyet tat ca cac dinh ke
	list<int> tmp=g[i];
	while(!tmp.empty()){
		j=tmp.front();
		traverse(j);
		tmp.pop_front();
	}
}
void BFS(int i){
	if(ok[i]) return;
	queue<int> q;
	int j,a;
	q.push(i);
	//ok[i]=true;//danh dau
	while(!q.empty()){
		j=q.front();
		q.pop();
		//cout<<j<<endl;
		if(!ok[j]) //neu chua duyet
		{
			list<int> tmp=g[j];
			while(!tmp.empty()){
				a=tmp.front();
				if(!ok[a])
				{
					q.push(a);
				}
				tmp.pop_front();
			}
		}
		ok[j]=true;
	}
}
