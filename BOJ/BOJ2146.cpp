#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct ver {
	int x, y;
};
int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[101][101];
vector<vector<int> > visit, visit2; // visit1은 
queue<ver> q; // bfs를 위한 queue
queue<ver> line; // 해안가 정보를 담은 queue
int num = 1;
int minD = 1e9;

int check() {

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || nx > n) continue;
			if (ny <= 0 || ny > n) continue;
			if (visit[ny][nx]) continue;
			if (!map[ny][nx]) {
				if (!visit2[y][x]) {
					line.push({ x,y });
					visit2[y][x] = 1;
				}
				continue;
			}
			q.push({ nx, ny });
			visit[ny][nx] = num;
		}
	}
	
	while (!line.empty()) {
		bool flag = false;
		int x = line.front().x;
		int y = line.front().y;
		line.pop();
		queue<ver> q1;
		visit2.clear();
		visit2.resize(n + 1, vector<int>(n + 1));
		q1.push({ x,y });
		int cnt = 0;
		while (!q1.empty()) {
			int size = q1.size();
			for (int k = 0; k < size; ++k) {
				int cx = q1.front().x;
				int cy = q1.front().y;
				visit2[cy][cx] = 1;
				q1.pop();

				for (int i = 0; i < 4; ++i) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx <= 0 || nx > n) continue;
					if (ny <= 0 || ny > n) continue;
					if (visit2[ny][nx]) continue;
					if (visit[ny][nx] == num) continue;
					if (map[ny][nx]) {
						minD = min(minD, cnt);
						flag = true;
						break;
					}
					q1.push({ nx, ny });
					visit2[ny][nx] = 1;
				}
				if (flag)
					break;
			}
			if (flag)
				break;
			cnt++;
		}
	}
	return minD;
}

int main()
{
	scanf("%d", &n);
	visit.resize(n + 1, vector<int>(n + 1));
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			visit2.clear();
			visit2.resize(n + 1, vector<int>(n + 1));
			if (visit[i][j]) continue;
			if (!map[i][j]) continue;
			visit[i][j] = num;
			q.push({ j,i });
			minD = check();
			num++;
		}
	}

	printf("%d", minD);
	return 0;
}