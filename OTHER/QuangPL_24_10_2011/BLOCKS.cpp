#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const long long f[4] = {0, 0, 1, 2};
long long n, k;

struct Matrix {
       long long a[2][2];
       Matrix (){}
       Matrix (int x, int y, int z, int t) {
              a[0][0] = x;
              a[0][1] = y;
              a[1][0] = z;
              a[1][1] = t;
       }
       Matrix operator * (const Matrix &that) const {
              Matrix result;
              result.a[0][0] = (a[0][0] * that.a[0][0] + a[0][1] * that.a[1][0]) % k;
              result.a[0][1] = (a[0][0] * that.a[0][1] + a[0][1] * that.a[1][1]) % k;
              result.a[1][0] = (a[1][0] * that.a[0][0] + a[1][1] * that.a[1][0]) % k;
              result.a[1][1] = (a[1][0] * that.a[0][1] + a[1][1] * that.a[1][1]) % k;
              return result;
       }
};

Matrix power(Matrix a, long long n) {
       Matrix ret(1, 0, 0, 1);
       while (n > 0) {
             if (n & 1) ret = ret * a;
             a = a * a;
             n >>= 1;
       }       
       return ret;
}

long long calc() {
     if (n < 4) return f[n] % k;
     
     Matrix a = Matrix(3, 1, -1, 0);
     Matrix p = power(a, n - 3);
     
     long long ret = (f[3] * p.a[0][0] + f[2] * p.a[1][0]) % k;
     return (ret + k) % k;
}

int main() {
    freopen("BLOCKS.INP", "r", stdin);
    freopen("BLOCKS.OUT", "w", stdout);
    
    cin >> n >> k;
    cout << calc();
    
    return 0;
}
