#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct Node {
    int h, w;
} n;
int tc;
int h, w;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visit[102][102][3];
char map[102][102];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> tc;
    while (tc--) {
        cin >> h >> w;
        deque<n> t_q;
        memset(map, '.', sizeof(map));
        memset(visit, -1, sizeof(visit));
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cin >> map[i][j];
                if (map[i][j] == '$'){
                    t_q.push_back({i, j});
                    map[i][j] = '.';
                }
            }
        }
        t_q.push_back({0, 0});
        for (int k = 0; k < 3; ++k) {
            deque<n> tmp_q;
            tmp_q.push_back(t_q.front());
            visit[tmp_q.front().h][tmp_q.front().w][k] = 0;
            t_q.pop_front();
            while (!tmp_q.empty()) {
                int curh = tmp_q.front().h;
                int curw = tmp_q.front().w;
                tmp_q.pop_front();

                for (int i = 0; i < 4; ++i) {
                    int nexth = curh + dy[i];
                    int nextw = curw + dx[i];
                    if (map[nexth][nextw] == '*' || visit[nexth][nextw][k] >= 0) continue;
                    if (nexth < 0 || nextw < 0 || nexth > h + 1 || nextw > w + 1) continue;
                    if (map[nexth][nextw] == '.') {
                        visit[nexth][nextw][k] = visit[curh][curw][k];
                        tmp_q.push_front({nexth, nextw});
                    }
                    if (map[nexth][nextw] == '#') {
                        visit[nexth][nextw][k] = visit[curh][curw][k] + 1;
                        tmp_q.push_back({nexth, nextw});
                    }
                }
            }
        }
        int ans = static_cast<int>(1e9);
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j){
                if(map[i][j] == '*') continue;
                int k = visit[i][j][0] + visit[i][j][1] + visit[i][j][2];
                if (map[i][j] == '#') k -= 2;
                ans = min(ans, k);
            }
        }
        cout << ans << endl;
    }
    return 0;
}