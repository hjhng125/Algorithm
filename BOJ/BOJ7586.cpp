#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<int> > map;
int visit[1001][1001];
queue<pair<int, int> > q;
int main()
{
	int m, n;
	
	scanf("%d %d", &m, &n);
	map.resize(n + 1, vector<int>(m + 1));
//	visit.resize(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push({ j, i });
				visit[i][j] = 1;
			}
		}
	}
	int day = -1;
	while(!q.empty()) {
		int size = q.size();
		day++;
		for (int i = 1; i <= size; ++i) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; ++j) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
				if (visit[ny][nx]) continue;
				if (map[ny][nx] == -1 || map[ny][nx] == 1) continue;
				visit[ny][nx] = 1;
				map[ny][nx] = 1;
				q.push({ nx,ny });
			}
		}	
	}
	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!map[i][j])
				flag = true;
		}
	}
	if (flag) printf("-1");
	else printf("%d", day);
}