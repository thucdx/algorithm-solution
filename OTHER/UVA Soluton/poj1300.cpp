#include <iostream>
#include <strstream>
using namespace std;

int Start, N, Total;
int Line[20];
char data[100];

void init(){
    cin >> Start >> N; 
    cin.getline(data, 100);
    int     i , t;
    memset ( Line , 0 , sizeof ( Line )); Total = 0;
    for ( i = 0; i < N; i ++ ) {
        cin.getline(data, 100);
        istrstream rin(data);
        while ( rin >> t ) { 
            Line[t]++; 
            Line[i]++; 
            Total++; 
        }
    }
    cin.getline(data, 100);
}

bool check(){
    int oddnum = 0 , oddlast , i;
    for (i = 0; i < N; i++) if (Line[i] % 2) {
        oddnum ++; oddlast = i;
    }
    return (oddnum == 0 && Start == 0) || (oddnum == 2 && oddlast == Start && oddlast);
}

int main(){
    while (cin >> data, strstr(data, "ENDOFINPUT") == NULL) {
                init();
                if (check()) cout << "YES " << Total << endl;
                        else cout << "NO" << endl;
    }
    return 0;
}
 
