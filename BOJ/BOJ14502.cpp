#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int map[9][9], Dtable[9][9], Btable[9][9];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs() {
	queue<pair<int, int> > q;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			if (Btable[i][j] == 2) q.push({ j,i });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
			if (Btable[ny][nx]) continue;
			Btable[ny][nx] = 2;
			q.push({ nx,ny });
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (Btable[i][j] == 0)
				ans++;
		}
	}

	return ans;
}
int dfs(int x, int y, int wall_num) {
	int ret = 0;
	if (wall_num == 3) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				Btable[i][j] = Dtable[i][j];
			}
		}
		return bfs();
	}
	int i = y;
	int j = x;
	for (; i <= n; ++i) {
		if (i != y) j = 1;
		for (; j <= m; ++j) {
			if (!Dtable[i][j]) {
				Dtable[i][j] = 1;
				ret = max(ret, dfs(j, i, wall_num + 1));
				Dtable[i][j] = 0;
			}
		}
	}
	return ret;

}
int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &map[i][j]);
			Dtable[i][j] = map[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!Dtable[i][j]) {
				Dtable[i][j] = 1;
				ans = max(ans, dfs(j, i, 1));
				Dtable[i][j] = 0;
			}
		}
	}
	printf("%d", ans);
}