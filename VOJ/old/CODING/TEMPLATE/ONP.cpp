#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stack>
using namespace std;
struct oper{
	char c;

	int prior;

}opers[5] ;
int getPrior(char c)
{	int i;
	for(i=0;i<=4;i++){
		if (opers[i].c==c)
			return opers[i].prior;
	}
	return 1;
}
int main()
{

	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	opers[0].c='+';
	opers[0].prior=1;

	opers[1].c='-';
	opers[1].prior=1;

	opers[2].c='*';
	opers[2].prior=2;

	opers[3].c='/';
	opers[3].prior=2;

	opers[4].c='^';
	opers[4].prior=3;
	stack<char> st ;
	int n,i,j;
	char c;
	string s;

	cin >>n;
	for(i=1;i<=n;i++){
		cin>>s;
		s='('+s+')';
		//xu li.
		int len=s.length();
		for(j=0;j<len;j++)
		{
			c=s[j];
			if('a'<=c  && c<='z') cout<<c;
			else
			{
				if(c=='(')
					st.push(c);
				else if(c==')'){
					while(st.top()!='(' && (!st.empty()))
					{
						char cc=st.top();
						st.pop();
						cout<<cc;
					}
					if(!st.empty())st.pop(); //pop '('
				}
				else  //c la toan tu.
				{
					int p=getPrior(c);
					while(st.top()!='(' && (getPrior(st.top())>p) && (!st.empty())){
						char cc=st.top();
						st.pop();
						cout<<cc;
					}
					st.push(c);
				}
			}

		}
		while(!st.empty()){
			cout<<st.top();
			st.pop();
		}
		cout<<endl;

	}
}

