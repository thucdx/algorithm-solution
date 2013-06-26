#include <iostream>
using namespace std;
#include <iostream>
#include <fstream>
#include <conio.h>
int main(){
    
    string list[]={"facebook.com","www.facebook.com","dantri.com","vietnamnet.vn"};   
    ofstream myfile;
    myfile.open ("C:\\Windows\\System32\\drivers\\etc\\hosts");
    for(int i=0;i<4;i++)
        myfile << "127.0.0.1"<<" "<<list[i]<<endl;
    myfile.close();
    getch();

}
