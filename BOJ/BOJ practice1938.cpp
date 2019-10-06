#include <iostream>
#include <queue>
using namespace std;

typedef struct B{
    int x, y, dir, cnt;
}b;
int n;
char map[51][51];
bool visit[51][51][2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool turn_check_value(int x, int y){
    for(int i = y - 1; i <= y + 1; ++i){
        for(int j = x - 1; j <= x + 1; ++j){
            if(map[i][j] == '1')
                return false;
        }
    }
    return true;
}
bool check_range(int x, int y, int dir){
    if(dir > 0)
        return !(x <= 0 || y - 1 <= 0 || x > n || y + 1 > n);
    return !(x-1 <= 0 || y <= 0 || x+1 > n || y > n);
}
bool check_value(int x, int y, int dir){
    if(dir > 0)
        return !(map[y-1][x] == '1' || map[y+1][x] == '1' || map[y][x] == '1');
    return !(map[y][x-1] == '1' || map[y][x+1] == '1' || map[y][x] == '1');
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> map[i][j];

    queue<b> q;
    int B_flag = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) {
            if (map[i][j] == 'B') {
                for (int k = 0; k < 4; ++k){
                    if(map[i+dy[k]][j+dx[k]] == 'B'){
                        if(k > 1)
                            B_flag = 1;
                        if(visit[i][j][B_flag]) continue;
                        q.push({j+dx[k], i+dy[k], B_flag, 0});
                        visit[i+dy[k]][j+dx[k]][B_flag] = true;
                        break;
                    }
                }
            }
        }
    }

    while(!q.empty()){
        int curx = q.front().x;
        int cury = q.front().y;
        int curdir = q.front().dir;
        int curans = q.front().cnt;
        int nextdir;
        if(curdir) nextdir = 0;
        else nextdir = 1;
        q.pop();

        if(curdir){
            if(map[cury-1][curx] == 'E' && map[cury+1][curx] == 'E'){
                cout << curans;
                return 0;
            }
        }
        else{
            if(map[cury][curx-1] == 'E' && map[cury][curx+1] == 'E'){
                cout << curans;
                return 0;
            }
        }
        for (int i = 0; i < 4; ++i){
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];

            if (!check_range(nextx, nexty, curdir)) continue;
            else if (!check_value(nextx, nexty, curdir)) continue;
            else if (visit[nexty][nextx][curdir]) continue;
            q.push({nextx, nexty, curdir, curans+1});
            visit[nexty][nextx][curdir] = true;
        }
        if (!check_range(curx, cury, nextdir)) continue;
        else if (!turn_check_value(curx, cury)) continue;
        else if (visit[cury][curx][nextdir]) continue;
        q.push({curx, cury, nextdir, curans+1});
        visit[cury][curx][nextdir] = true;

    }
    cout << 0;
    return 0;
}