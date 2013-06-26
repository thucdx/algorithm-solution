#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct point {
    int x;
    int y;
    int num;
    int step;
    bool friend operator < (point a, point b) {
        return a.step > b.step;
    }
}temp, tt;

char map[110][110];
vector < point > vec[101][101];
int n, m;
int hash[101][101];
priority_queue < point > q;
__int8 visit[100][100][27];
int ans;

//??
void bfs(int x, int y) {

    int i;
    temp.x = x;
    temp.y = y;
    memset(hash, 0, sizeof(hash));
    while(!q.empty() )
        q.pop();

    q.push( temp );
    hash[ temp.x ][ temp.y ] = 1;

    while(!q.empty()) {

        temp = q.top();
        q.pop();
        for(i = 0; i < 4; i++) {
            tt.x = temp.x + dir[i][0];
            tt.y = temp.y + dir[i][1];

            if(tt.x < 0 || tt.y < 0 || tt.x == n || tt.y == m)
                continue;
            if(map[tt.x][tt.y] == '*') 
                continue;
            if(map[tt.x][tt.y] >= 'A' && map[tt.x][tt.y] <= 'Z')
                continue;
            if(map[tt.x][tt.y] == '#')
                continue;
            if(hash[ tt.x ][ tt.y ])
                continue;

            if(!hash[ tt.x ][ tt.y ] ) {
                hash[ tt.x ][ tt.y ] = 1;

                if(map[tt.x][tt.y] == '.')
                    q.push( tt );
                else {
                    vec[x][y].push_back( tt );
                }
            }
        }
    }
}

int BFS(int x, int y, int num) {

    int i;
    temp.step = 0;
    temp.x = x;
    temp.y = y;
    temp.num = num;

    while(!q.empty())
        q.pop();

    memset(visit, -1, sizeof(visit));
    q.push( temp );

    visit[ temp.x ][ temp.y ][ temp.num ] = 0;

    while( !q.empty() ) {
        temp = q.top();
        q.pop();

        if(temp.step > ans && ans != -1)
            return -1;

        if( map[ temp.x ][ temp.y ] == '$')
            return temp.step;

        int size = vec[ temp.x ][ temp.y ].size();

        for(i = 0; i < size; i++) {
            point rt = vec[ temp.x ][ temp.y ][ i ];

            if(map[rt.x][rt.y] == '$') {
                tt.num = temp.num;
                tt.step = temp.step;

                tt.x = rt.x;
                tt.y = rt.y;
                if(tt.step < visit[ tt.x ][ tt.y ][ tt.num ]
                    || visit[ tt.x ][ tt.y ][ tt.num ] == -1) {
                    visit[ tt.x ][ tt.y ][ tt.num ] = tt.step;
                    q.push( tt );
                }
                continue;
            }

            if(temp.num) {
                tt.num = temp.num - 1;
                tt.step = temp.step;
                tt.x = rt.x;
                tt.y = rt.y;
                if(tt.step < visit[ tt.x ][ tt.y ][ tt.num ]
                    || visit[ tt.x ][ tt.y ][ tt.num ] == -1) {
                    visit[ tt.x ][ tt.y ][ tt.num ] = tt.step;
                    q.push( tt );
                }
            }

            tt.num = temp.num;
            tt.step = temp.step + map[rt.x][rt.y] - '0';
            tt.x = rt.x;
            tt.y = rt.y;

            if(tt.step < visit[ tt.x ][ tt.y ][ tt.num ]
                || visit[ tt.x ][ tt.y ][ tt.num ] == -1) {
                visit[ tt.x ][ tt.y ][ tt.num ] = tt.step;
                q.push( tt );
            }
        }
    }

    return -1;
}

int main() {
    int i, j;
    while(1) {

        while(gets(map[0])) {
            if( strcmp(map[0], "") )
                break;
        }        
        m = strlen( map[0] );

        if(strcmp(map[0], "--") == 0)
            break;

        n = 1;
        while(gets(map[n])) {
            if(strcmp( map[n], "" ) == 0)
                break;
            else
                n ++;
        }

        for(i = 0; i < n; i++) {
            for(j = 0;j < m; j++)
                vec[i][j].clear();
        }

        for(i = 0; i < n; i++) {

            for(j = 0; j < m; j++) {

                if(map[i][j] >= '1' && map[i][j] <= '9') {
                    bfs(i, j);
                }

                if(map[i][j] >= 'A' && map[i][j] <= 'Z' || map[i][j] == '#') {
                    bfs(i, j);
                }
            }
        }

        ans = -1;
        
        for(i = 0; i < n; i++) {

            for(j = 0; j < m; j++) {

                if(map[i][j] >= 'A' && map[i][j] <= 'Z') {
                    int ty = BFS(i, j, map[i][j]-'A'+1);
                    if(ty != -1) {
                        if(ty < ans || ans == -1)
                            ans = ty;
                    }
                }
                if(map[i][j] == '#') {
                    int ty = BFS(i, j, 0);    
                    if(ty != -1) {
                        if(ty < ans || ans == -1)
                            ans = ty;
                    }
                }
            }
        }

        if(ans == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);

    }
    return 0;
}
