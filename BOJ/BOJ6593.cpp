#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

typedef struct building {
	int l, r, c;
};
int l, r, c;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
char map[31][31][31];
bool visit[31][31][31];
int main()
{
	while (1) {
		queue<building> q;
		memset(visit, 0, sizeof(visit));
		memset(map, ' ', sizeof(map));
		scanf("%d %d %d", &l, &r, &c);
		if (!l && !r && !c)
			break;

		for (int i = 0; i < l; ++i) 
			for (int j = 0; j < r; ++j) 
				scanf("%s", map[i][j]);

		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < c; ++k) {
					if (map[i][j][k] == 'S') {
						q.push({ i,j,k });
						visit[l][r][c] = true;
					}
				}
			}
		}
		int time = 0;
		bool flag = false;
		while (!q.empty()) {
			int size = q.size();
			for (int idx = 0; idx < size; ++idx) {
				int cc = q.front().c;
				int cr = q.front().r;
				int cl = q.front().l;
				q.pop();
				if (map[cl][cr][cc] == 'E') {
					printf("Escaped in %d minute(s).\n", time);
					flag = true;
					break;
				}
				for (int i = 0; i < 6; ++i) {
					int nc = cc + dx[i];
					int nr = cr + dy[i];
					int nl = cl + dz[i];

					if (nc < 0 || nr < 0 || nl < 0 || nc >= c || nr >= r || nl >= l) continue;
					if (visit[nl][nr][nc]) continue;
					if (map[nl][nr][nc] == '#') continue;
					q.push({ nl, nr, nc });
					visit[nl][nr][nc] = true;
				}
			}
			if (flag)
				break;
			time++;
		}
		if (!flag) printf("Trapped!\n");
	}
}