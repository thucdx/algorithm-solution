
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n;
	string s;
	cin>>n;
	while(getchar()!='\n');

	for(int i=1;i<=n;i++){
		getline(cin,s);
		cout<<s<<endl;
		int result=0;
		int len=s.length();
		s=s+"___";
		for(int j=0;j<len;j++){
			if(s[j]==':')
			{
				if(s[j+1]=='(' && s[j+2]!='(')
				{
					result+=-1;
					continue;
				}
				if(s[j+1]=='(' && s[j+2]=='(')
				{
					result+=-5;
					continue;
				}
				if(s[j+1]==')' && s[j+2]!=')')
				{
					result+=2;
					continue;
				}
				if(s[j+1]==')' && s[j+2]==')')
				{
					result+=4;
					continue;
				}

			}

		}
		cout<<result<<endl;
	}
}
