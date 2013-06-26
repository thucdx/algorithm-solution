#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b){if (b == 0) return a; return gcd(b, a%b);}
int lcm(int a, int b){return a/gcd(a,b) * b;}

struct Fraction{
	int a, b;
	int sign(int x){return x>0?1:-1;}
	Fraction():a(0),b(1){}
	Fraction(int x):a(x), b(1){}
	Fraction(int x, int y){
		int m = gcd(abs(x), abs(y));
		a = x/m * sign(y);
		if (a == 0) b = 1; else b = abs(y/m);
	}
	int get_denominator(){return b;}
	Fraction operator + (const Fraction &f){
		int m = gcd(b, f.b);
		return Fraction(f.b/m * a +b/m * f.a, b/m * f.b);	
	}
	Fraction operator - (const Fraction &f){
		int m = gcd(b, f.b);
		return Fraction(f.b/m * a - b/m*f.a, b/m * f.b);
	}
	Fraction operator * (const Fraction &f){
		int m1 = gcd(abs(a), f.b);
		int m2 = gcd(b, abs(f.a));
		return Fraction( (a/m1)*(f.a/m2), (b/m2)*(f.b/m1) );	
	}
	friend ostream & operator << (ostream &out, const Fraction &f){
		if (f.a == 0) cout << 0; else
			if (f.b == 1) cout << f.a; else cout << f.a << '/' << f.b;
		return out;
	}
};

int c[22][22];
Fraction a[22];

int main(){
	int i, j, k, m;
	c[0][0] = 1;
	for (i = 1; i <= 21; i++){
		c[i][0] = 1; c[i][i] = 1;
		for (j = 1; j < i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	a[0] = 0;
	while (cin >> k){
		a[k+1] = Fraction(1, k+1);
		m = k + 1;
		for (i = k; i >= 1; i--){
			a[i] = 0;
			for (j = i + 1; j <= k + 1; j++)
				if ((j-i+1)%2 == 0) a[i] = a[i] + a[j]*c[j][j-i+1];
				else a[i] = a[i] - a[j]*c[j][j-i+1];
			a[i] = a[i] * Fraction(1, i);
			m = lcm(m, a[i].get_denominator());	
		}	
		cout << m << " ";
		for (i = k + 1; i > 0; i--) cout << a[i] * m << " ";
		cout << "0\n";
	}
	return 0;	
}
