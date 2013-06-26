#include <sstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main() {
	vector <string> str;
	string s;
	do{
		getline(cin,s);
		if(s=="x") break;
		str.clear();
		stringstream ss;
		ss<<s;
		while(ss>>s) str.push_back(s);
		for (int i=str.size()-1;i>=0;i--) cout<<str[i]<<" ";
	}while(true);
	return 0;
}
