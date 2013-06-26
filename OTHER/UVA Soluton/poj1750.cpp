#include <algorithm>
#include <string.h>
using namespace std;

char a[100], b[100];

int main(){
		int x = 0, y = 0, l1, l2, i;
		gets(b);  puts(b);
		while (gets(a) && a[0]){
			l1 = strlen(a);  l2 = strlen(b);
			for (i = 0; i < l1 && i < l2 && a[i] == b[i]; i++);
			if (i > y) x++; else x = i;
			y = x;
			for (i = 0; i < x; i++) putchar(' ');
			puts(a);
			strcpy(b, a);
		}
		return 0;	
}
