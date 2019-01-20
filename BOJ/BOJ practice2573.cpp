#include<cstdio>
#include<queue>
#include<cstring>
#define MAX 301

using namespace std;
typedef pair<int, int> pi;

int r, c, sr ,sc;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[MAX][MAX], numZero[MAX][MAX];
bool visit[MAX][MAX];


void update() {
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (map[i][j] - numZero[i][j] >= 0)
				map[i][j] -= numZero[i][j];
			else map[i][j] = 0;
		}
	}
}
void bfs(int y, int x) {

	queue<pi> q;
	q.push({ y,x });
	visit[y][x] = true;

	while (!q.empty()) {
		pi cur = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny > r || nx > c || ny <= 0 || nx <= 0 || visit[ny][nx]) continue;
			if (!map[ny][nx]) {
				numZero[cur.first][cur.second]++;
				continue;
			}
			q.push({ ny,nx });
			visit[ny][nx] = true;
		}
	}
}

int main()
{
	scanf("%d %d", &r, &c);

	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			scanf("%d", &map[i][j]);
		}
	}

	int y = 0;
	while (1) {
		int cnt = 0;
		update();
		memset(visit, false, sizeof(visit));
		memset(numZero, 0, sizeof(numZero));
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				if (!visit[i][j] && map[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		
		if (cnt > 1) {
			printf("%d", y);
			return 0;
		}
		if (!cnt) {
			printf("0");
			return 0;
		}
		y++;
	}
}