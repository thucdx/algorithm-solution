#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
vector <string> BinaryCode(string s);
int main()
{
	string s;
	cin>>s;
	vector<string> rs= BinaryCode(s);
	cout<<"{"""<<rs[1]<<""", """<<rs[2]<<"""}"<<endl;

}
vector <string> BinaryCode(string s)
{
	vector<string> rs;
	string first,second ;
	//Test 1.
	int i;
	first[0]='0';
	if(s.length()==1)
	{
		if(s[0]!='0')
			first="NONE";
	}
	else if(s.length()>=2)
	{
		first[1]=s[1]-s[0];
		if(first[1]>='2') first="NONE";
		else
			for(i=2;i<s.length();i++){
				first[i]=s[i-1]-first[i-1]-first[i-2]+2*'0';
				if(first[i]>='2')
					{first="NONE";
					break;}

			}

			}
	}

}
