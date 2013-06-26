#include <stdio.h>
#include <string.h>

int     pnt[30000], p[30000];
int     n;
int     a, b;
char    s[30000];


int main()
{
    int     cases = 0, i, h, pos, pre, l;
	while (1)
	{
		gets(s);
		if (s[0] == '#') break;
		printf("Tree %ld: ", ++cases);
		a = b = 0;
		h = n = 0;
		pos = 0;
		p[0] = 0;
		l = strlen(s);
		for (i = 0; i < l; i++)
			if (s[i] == 'd')
			{
				n++;  h++;
				if (h > a) a = h;
				pnt[n] = pos;
				if (i > 0 && s[i-1] == 'u')
				{
					p[n] = p[pre] + 1;
					if (p[n] > b) b = p[n];
				}
				else
				{
					p[n] = p[pos] + 1;
					if (p[n] > b) b = p[n];
				}
				pos = n;
			}
			else
			{
				pre = pos;
				pos = pnt[pos];
				h--;
			}
			printf("%d => %d\n", a, b);		
	}
	return 0;
}

