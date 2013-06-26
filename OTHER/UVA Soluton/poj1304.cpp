#include <iostream>
#include <strstream>
using namespace std;

int Time;
int N, Min;
int M;
int len[30];
int Cost[30][11];
char data[1000];

bool init(){
    cin >> data;
    if (strcmp(data, "ENDOFINPUT") == 0) return false;
        cin >> N; cin.getline(data, 1000);
        for (int i = 0; i < N; i++) {
            cin.getline(data, 1000);
            len[i] = Cost[i][0] = 0;
            istrstream rin (data);
            while (rin >> Cost[i][len[i] + 1]) {
                len[i] ++;
                Cost[i][0] += Cost[i][len[i]];
            }
        }
    cin >> Time;
    cin >> data;
    return true;
}

int main(){
    while (init()) {
        Min = 999999999;
        for (int i = 0; i < N; i ++ ) {
            int j, T = Time % Cost[i][0];
            for (j = 1; T >= Cost[i][j]; j++ ) T -= Cost[i][j];
            if ( T ) T = Cost[i][j] - T;
            if ( T < Min ) Min = T;
        }
        cout << Min << endl;
    }
    return 0;
}
 
