#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N , i, c = 0;
int numbers[100005], A[100005], B[100005], L[100005], R[100005], hieu, tong;// A la S1, B la S2

bool check(int j)
{
     hieu = R[j] - A[j-1];
     tong = L[j-1] + B[j];
     //cout << "j = " << j <<" hieu : " << hieu << " tong : " << tong << endl;
   if( tong > 0 && hieu > 0) return true;
   return false;
}
int main()
{
    
    cin >> N;
    for(i = 1; i <= N; ++i){
           cin >> numbers[i];
           //cout << numbers[i] << endl;
    }
   A[0] = 0;
   for(i = 1; i <= N; ++i){
         A[i] = A[i-1] + numbers[i];
         //cout << "A thu " << i << " la : " << A[i] << endl;
   }
   B[N+1] = 0;
   for(i = N; i >= 1; --i){
         B[i] = B[i+1]+numbers[i];
        // cout << "    B thu " << i << " la : " << B[i] << endl;
   }
   L[1] = A[1];
   for(i = 2; i <= N; ++i){
         L[i] = min(L[i-1],A[i]);
         //cout << "***  L thu " << i << " la : " << L[i] << endl;
   }
   R[N] = A[N];
   for(i = N-1; i >= 1; --i){
         R[i] = min(R[i+1],A[i]); //cout << "********** R thu " << i << " la : " << R[i] << endl;
   }
   R[0] = 0;
   for(i = 1; i <= N; ++i)
          c += check(i);
    cout << c;
    return 0;
}

