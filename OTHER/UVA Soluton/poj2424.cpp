#include <cstdio>

const int maxlen = 100;

class HP
{
	public:
		int len;
		int s[maxlen];
		void print();
		HP mul(const int b);
		HP div(const int b);
};

void HP::print()
{
	for (int i = len; i > 0; i--)
		printf("%d", s[i]);
	printf("\n");
}

HP HP::mul(const int b)
{
	HP c;
	int i, t = 0;
	for (i = 1; i <= len; i++)
	{
		t += s[i] * b;
		c. s[i] = t % 10;
		t /= 10;
	}
	c.len = len;  
	while (t)
	{
		c.len++;
		c. s[c.len] = t % 10;
		t /= 10;
	}
	return c;
}


HP HP::div(const int b)
{
	HP c;
	int i, t = 0;
	for (i = len; i > 0; i--)
	{
		t = t * 10 + s[i];
		c. s[i] = t / b;
		t = t % b;
	}
	c. len = len;
	while (c. len > 1 && c. s[c. len] == 0) c. len--; 
	return c;
}


HP data[101];


void prework()
{
	data[1].len = 1;
	data[1].s[1] = 1;
	for (int i = 1; i < 100; i++)
		data[i + 1] = data[i]. mul(4 * i + 2). div(i + 2);
}


int main()
{
	prework();
	int n;
	while (scanf("%d", &n) == 1 && n != -1)
		data[n].print();
	return 0;
}
