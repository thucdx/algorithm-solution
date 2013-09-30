ccy??:

#include<iostream>
using namespace std;

const int maxn=1000010;

struct
{
    int step;//???????????step?
    int size;//?????size???
}group[maxn];//????????

int group_num;//??
int n,m;
int nim;

int first()
{
    int sum=0;
    int next_group_size;
    for (int i=1;i<=group_num;i++)
        if (group[i].step&1)//????,?????????
        {
            if ((group[i].size^nim)<group[i].size) sum++;
        }
        else
            if (group[i].step!=2)//?????????,?????2?,????1??,?????
            {
                if (i==group_num || group[i+1].step+1!=group[i].step)
                    next_group_size=0;//??????????
                else
                    next_group_size=group[i+1].size;
                int cut=(next_group_size^nim)-next_group_size;//????????????
                if (cut>0 && group[i].size>=cut) sum++;
            }
    return sum;
}

void solve()
{
    int cover,last_cover;//cover:??????????,last_cover:?????????????
    int size,left;//size:????????,left:???????????

    scanf("%d%d",&m,&n);

    nim=group_num=0;
    left=n;
    scanf("%d",&cover);
    while (1==1)
    {
        size=0;
        last_cover=cover;
        while (1==1)
        {
            size++;
            left--;
            if (left==0) break;
            scanf("%d",&cover);
            if (cover!=last_cover+1) break;
            last_cover=cover;
        }
        group_num++;
        group[group_num].size=size;
        group[group_num].step=m-last_cover-left;//???????!!!
        if (group[group_num].step&1)//??????
            nim^=group[group_num].size;
        if (left==0) break;
    }

    if (last_cover==m-1) printf("%d\n",size);
    else
        if (nim==0) printf("0\n");
        else printf("%d\n",first());
}

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);

    solve();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
