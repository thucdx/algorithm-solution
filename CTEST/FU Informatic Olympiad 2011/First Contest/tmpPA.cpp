#include <iostream>
using namespace std;
#include <conio.h>
int main()
{
    int num;
    cin >> num;
    
    for(int ind = 0; ind < num; ind++)
    {
        char cha[100], chb[100];
        scanf("%s %s", cha, chb);
        
        int n1 = strlen(cha);
        int n2 = strlen(chb);

        int memo = 0;
        char result[100];
        for(int index = 0; index < 100; index++) result[index] = '\0';
        //result[0] = '\0';
        int i = n1-1;
        int j = n2-1;
        while(true)
        {
            int op1 = 0;
            int op2 = 0;
            if(i>=0)
                if(cha[i]=='1') op1 = 1;
            if(j>=0)
                if(chb[j]=='1') op2 = 1;
            int tpRes = op1 + op2 + memo;
            if(tpRes>=2)
            {
                tpRes -= 2;
                memo = 1;
            }
            else
                memo = 0;
            
            for(int k = strlen(result); k>=1; k--)
            {
                 result[k] = result[k-1];
            }
            result[strlen(result)+1] = '\0';
            result[0] = tpRes + '0';
            
            i--;
            j--;
            if(i<0&&j<0)
                break;
        }
        
        if(memo!=0)
        {
            int a = strlen(result);
            for(int k = a; k>=1; k--)
            {
                 result[k] = result[k-1];
            }
            result[a+1] = '\0';
            result[0] = '1';
        }

        int a = strlen(result);
        int ind3 = 0;
        cout << (ind +1 ) << " ";
        while(result[ind3]=='0'&&ind3<a-1) ind3++;
        for(int ind2 = ind3; ind2 <=a-1; ind2++)
            cout << result[ind2];
        cout << endl;
    }
}
