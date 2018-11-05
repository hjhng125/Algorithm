#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int n, map[101][101], visit[101][101];
int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int> > q;
int main()
{
	scanf("%d", &n);
	int maxV = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &map[i][j]);
			maxV = max(maxV, map[i][j]);
		}
	}
	int max_cnt = 0;
	for (int i = 1; i <= maxV; ++i) {
		memset(visit, 0, sizeof(visit));
		
		int cnt = 0;
		for (int idx1 = 1; idx1 <= n; ++idx1) {
			for(int idx2 = 1;idx2 <= n; ++idx2){
				if (visit[idx1][idx2] || map[idx1][idx2] < i)
					continue;
				visit[idx1][idx2] = 1;
				q.push({ idx2, idx1 });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int j = 0; j < 4; ++j) {
						int nx = x + dx[j];
						int ny = y + dy[j];

						if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
						if (visit[ny][nx]) continue;
						if (map[ny][nx] < i) continue;
						visit[ny][nx] = 1;
						q.push({ nx, ny });
					}
				}
				cnt++;
			}
		}
		max_cnt = max(cnt, max_cnt);
	}
	printf("%d", max_cnt);
}