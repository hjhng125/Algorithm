#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int n, m;
char map[51][51];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool visit[51][51];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) 
		scanf("%s", map[i]);

	queue<pair<int, int> > q;
	int  max_time = 0;
	for (int idx1 = 0; idx1 < n; idx1++) {
		for (int idx2 = 0; idx2 < m; idx2++) {
			int time = -1;
			memset(visit, false, sizeof(visit));
			if (map[idx1][idx2] == 'L')
				q.push({ idx2, idx1 });
			while (!q.empty()) {
				int size = q.size();
				for (int idx = 1; idx <= size; ++idx) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int i = 0; i < 4; ++i) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
						if (visit[ny][nx]) continue;
						if (map[ny][nx] == 'W') continue;
						q.push({ nx, ny });
						visit[ny][nx] = true;
					}
				}
				time++;
			}
			max_time = max(max_time, time);
		}
	}
	printf("%d", max_time);
}