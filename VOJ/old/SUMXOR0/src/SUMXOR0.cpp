#include <iostream>
int main() {
	int n,s;
	cin>>n;
	s=n;
	while(--n) s^=n;
	cout<<s;
}
