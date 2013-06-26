#include <algorithm>
using namespace std;

const char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main(){
	int n;
	scanf("%d", &n);
	printf("%d %d %d\n", 2, n, n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			putchar(s[i]);
		putchar('\n');
	}
	puts("");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			putchar(s[j]);
		putchar('\n');
	}
	return 0;	
}
