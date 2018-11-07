#include<cstdio>
#include<queue>
using namespace std;

int m, n, h;
int tmt[101][101][101], visit[101][101][101];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
typedef struct tomato{
	int x, y, z;
};
queue<tomato> q;
int main()
{
	scanf("%d %d %d", &m, &n, &h);
	for (int k = 1; k <= h; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &tmt[i][j][k]);
				if (tmt[i][j][k] == 1)
					q.push({ j, i, k });
			}
		}
	}
	int day = -1;
	while (!q.empty()) {
		int size = q.size();

		for (int idx = 1; idx <= size; ++idx) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();

			for (int i = 0; i < 6; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx <= 0 || ny <= 0 || nz <= 0 || nx > m || ny > n || nz > h) continue;
				if (visit[ny][nx][nz]) continue;
				if (tmt[ny][nx][nz]) continue;
				visit[ny][nx][nz] = 1;
				tmt[ny][nx][nz] = 1;
				q.push({ nx,ny,nz });
			}
		}
		day++;
	}
	bool flag = false;
	for (int k = 1; k <= h; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (!tmt[i][j][k])
					flag = true;
			}
		}
	}
	if (flag) printf("-1");
	else printf("%d", day);
}