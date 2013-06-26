#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int ind = 0; ind < num; ind++)
    {
        int a;
        cin >> a;
        int qua, dim, nic, pen;
        qua = a/25;
        a %= 25;
        dim = a/10;
        a %= 10;
        nic = a / 5;
        a %= 5;
        pen = a;
        cout << (ind+1) << " " << qua << " QUARTER(S), " << dim << " DIME(S), " << nic << " NICKEL(S), " << pen << " PENNY(S)" << endl;          
    }   
}
