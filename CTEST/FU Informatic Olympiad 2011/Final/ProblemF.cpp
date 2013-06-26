//ok
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct point 
{
    int x,y;
    int dir;
};

char b[9][9];
point pos;
char str[10],cmd[10];
int step;
int dis[9][9];

int main()
{
    int i,j,k;
    while(1)
    {
        for(i=1;i<=8;++i)
        {
            for(j=1;j<=8;++j)
            {
                scanf("%c",&b[i][j]);
                if(i==1 && j==2 && b[1][1]=='-' && b[1][2]=='-')
                {
//                    printf("*");
 //                   system("PAUSE");
                    return 0;
                }
                if(b[i][j]=='v')
                {
                    pos.dir=0;
                    pos.x=j;
                    pos.y=i;
                }
                else if(b[i][j]=='<')
                {
                    pos.dir=1;
                    pos.x=j;
                    pos.y=i;
                }
                else if(b[i][j]=='^')
                {
                    pos.dir=2;
                    pos.x=j;
                    pos.y=i;
                }
                else if(b[i][j]=='>')
                {
                    pos.dir=3;
                    pos.x=j;
                    pos.y=i;
                }
            }
            getchar();
        }
        while(1)
        {
            scanf("%s",str);
            if(strcmp(str,"#")==0)
            {
//                printf("*");
                break;
            }
            if(strcmp(str,"move")==0)
            {
                scanf("%d",&step);
                if(pos.dir==3)
                {
                    b[pos.y][pos.x]='.';
                    k=0;//?pos?????????? 
                    for(i=pos.x+1;i<=8;++i)
                    {
                        if(b[pos.y][i]=='.')
                        {
                            k++;
                            if(k>=step)break;
                        }
                        else
                        {
                            dis[pos.y][i]=k;
                        }
                    }
                    for(j=i-1;j>pos.x;--j)
                    {
                        if(b[pos.y][j]=='.')continue;
                        if(j+(step-dis[pos.y][j])>8)
                        {
                            b[pos.y][j]='.';
                            continue;
                        }
                        b[pos.y][j+(step-dis[pos.y][j])]=b[pos.y][j];
                        b[pos.y][j]='.';
                    }
                    pos.x+=step;
                    if(pos.x>8)pos.x=8;
                }
                else if(pos.dir==1)
                {
                    b[pos.y][pos.x]='.';
                    k=0;//?pos?????????? 
                    for(i=pos.x-1;i>=1;--i)
                    {
                        if(b[pos.y][i]=='.')
                        {
                            k++;
                            if(k>=step)break;
                        }
                        else
                        {
                            dis[pos.y][i]=k;
                        }
                    }
                    for(j=i+1;j<pos.x;++j)
                    {
                        if(b[pos.y][j]=='.')continue;
                        if(j-(step-dis[pos.y][j])<=0)
                        {
                            b[pos.y][j]='.';
                            continue;
                        }
                        b[pos.y][j-(step-dis[pos.y][j])]=b[pos.y][j];
                        b[pos.y][j]='.';
                    }
                    pos.x-=step;
                    if(pos.x<=0)pos.x=1;
                }
                else if(pos.dir==2)
                {
                    b[pos.y][pos.x]='.';
                    k=0;//?pos?????????? 
                    for(i=pos.y-1;i>=1;--i)
                    {
                        if(b[i][pos.x]=='.')
                        {
                            k++;
                            if(k>=step)break;
                        }
                        else
                        {
                            dis[i][pos.x]=k;
                        }
                    }
                    for(j=i+1;j<pos.y;++j)
                    {
                        if(b[j][pos.x]=='.')continue;
                        if(j-(step-dis[j][pos.x])<=0)
                        {
                            b[j][pos.x]='.';
                            continue;
                        }
                        b[j-(step-dis[j][pos.x])][pos.x]=b[j][pos.x];
                        b[j][pos.x]='.';
                    }
                    pos.y-=step;
                    if(pos.y<=0)pos.y=1;
                }
                else if(pos.dir==0)
                {
                    b[pos.y][pos.x]='.';
                    k=0;//?pos?????????? 
                    for(i=pos.y+1;i<=8;++i)
                    {
                        if(b[i][pos.x]=='.')
                        {
                            k++;
                            if(k>=step)break;
                        }
                        else
                        {
                            dis[i][pos.x]=k;
                        }
                    }
                    for(j=i-1;j>pos.y;--j)
                    {
                        if(b[j][pos.x]=='.')continue;
                        if(j+(step-dis[j][pos.x])>8)
                        {
                            b[j][pos.x]='.';
                            continue;
                        }
                        b[j+(step-dis[j][pos.x])][pos.x]=b[j][pos.x];
                        b[j][pos.x]='.';
                    }
                    pos.y+=step;
                    if(pos.y>8)pos.y=8;
                } 
            }
            if(strcmp(str,"turn")==0)   
            {
                scanf("%s",cmd);
                if(strcmp(cmd,"left")==0)
                {                    
                    pos.dir=(pos.dir+3)%4;
                }
                else if(strcmp(cmd,"right")==0)
                {                    
                    pos.dir=(pos.dir+1)%4;
                }
                else if(strcmp(cmd,"back")==0)
                {                    
                    pos.dir=(pos.dir+2)%4;
                }
            }
        }
        for(i=1;i<=8;++i)
        {
            for(j=1;j<=8;++j)
            {
                if(pos.x==j && pos.y==i)
                {
                    if(pos.dir==0)
                    {
                        printf("v");
                    }
                    else if(pos.dir==1)
                    {
                        printf("<");
                    }
                    else if(pos.dir==2)
                    {
                        printf("^");
                    }
                    else if(pos.dir==3)
                    {
                        printf(">");
                    }
                }
                else
                {
                    printf("%c",b[i][j]);
                }
            }
            printf("\n");
        }   
        printf("\n"); 
        getchar();               
    }
}
