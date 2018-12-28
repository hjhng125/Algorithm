#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>

using namespace std;

char RGB[101][101];
int n, visit[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int> > q;

void bfs() {
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[ny][nx]) continue;
			if (RGB[curY][curX] != RGB[ny][nx]) continue;
			q.push(make_pair(nx, ny));
			visit[ny][nx] = 1;
		}
	}
}
void rgbBfs() {
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[ny][nx]) continue;
			if (RGB[curY][curX] == 'B' && (RGB[ny][nx] == 'R' || RGB[ny][nx] == 'G')) continue;
			if ((RGB[curY][curX] == 'R' || RGB[curY][curX] == 'G') && RGB[ny][nx] == 'B') continue;
			q.push(make_pair(nx, ny));
			visit[ny][nx] = 1;
		}
	}
}
int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		scanf("%s", RGB + i);
	}
	int cnt = 0, cntrgb = 0;	

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j]) {
				q.push(make_pair(j, i));
				visit[i][j] = 1;
				bfs();
				cnt++;
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j]) {
				q.push(make_pair(j, i));
				visit[i][j] = 1;
				rgbBfs();
				cntrgb++;
			}
		}
	}

	printf("%d %d", cnt, cntrgb);
}