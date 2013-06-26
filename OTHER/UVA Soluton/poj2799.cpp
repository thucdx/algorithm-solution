#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int pow[8]={1,2,4,8,16,32,64,128};
int num[1000][4],ip[1000][32], minip[32],mip[4],h[32],inum[4];
char ips[40];
int n,i,j,k,ptr,tp,flag,a;

int main () 
{
		scanf("%d", &n);
        for(i=0;i<n;i++){
            scanf("%s",ips);
            tp=strlen(ips);
            ips[tp+1]=0; ips[tp]='.';
            tp=0; ptr=0;
            for(j=0;j<strlen(ips);j++)
                if(ips[j]!='.'){
                    tp*=10; tp+=ips[j]-'0'; 
                }
                else{
                    num[i][ptr++]=tp;
                    tp=0;                
                }    
            for(j=3;j>=0;j--)       
                for(k=(j+1)*8-1;k>=j*8;k--){
                    if(num[i][j]%2==0) ip[i][k]=0;
                        else ip[i][k]=1;
                    num[i][j]/=2;
                }

        }   
        i=0;
        while(i<32){
            flag=1; a=ip[0][i];
            for(j=1;j<n;j++)   
                if(ip[j][i]!=a){ 
                    flag=0; break; 
                }
            if(flag==1) i++; else break;
        }
		//puts("!!");
        for(j=0;j<i;j++){
            minip[j]=ip[0][j]; ips[j]=1;
        }
        //printf("%d!!", i);
        for(j=i;j<32;j++){
		//	printf("%d\n", j);
            minip[j]=0; ips[j]=0;
        }
        //puts("!!");
        for(i=0;i<4;i++){
            mip[i]=0; inum[i]=0;
            for(j=0;j<8;j++){
                if(minip[i*8+j]==1) mip[i]+=pow[7-j];
                if(ips[i*8+j]==1) inum[i]+=pow[7-j];
            }
        }
        printf("%d.%d.%d.%d\n",mip[0],mip[1],mip[2],mip[3]);
        printf("%d.%d.%d.%d\n",inum[0],inum[1],inum[2],inum[3]);
        //system("pause");
}

