#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

queue <pair<int, int> > q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char puyo[13][7];
vector<vector<int> > visit;
int ans = 0;
bool flag;
bool bfs() {
	int cnt = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int idx = 0; idx < 4; ++idx) {
			int nx = cur.second + dx[idx];
			int ny = cur.first + dy[idx];

			if (ny < 1 || ny > 12) continue;
			if (nx < 1 || nx > 6) continue;
			if (visit[ny][nx]) continue;
			if (puyo[cur.first][cur.second] != puyo[ny][nx]) continue;
			q.push({ ny, nx });
			visit[ny][nx] = 1;
			cnt++;
		}
	}
	if (cnt >= 4) {
		for (int i = 1; i <= 12; ++i) {
			for (int j = 1; j <= 6; ++j) {
				if (visit[i][j])
					puyo[i][j] = '.';
			}
		}
		return true;
	}
	else {
		for (int i = 1; i <= 12; ++i) {
			for (int j = 1; j <= 6; ++j) {
				visit[i][j] = 0;
			}
		}
		return false;
	}
}
void update() {
	for (int i = 1; i <= 12; ++i) {
		for (int j = 1; j <= 6; ++j) {
			if (puyo[i][j] == '.') {
				for (int k = i; k > 0; --k) {
					if (k == 1)
						puyo[k][j] = '.';
					else
						puyo[k][j] = puyo[k - 1][j];
				}
			}
		}
	}
}
void print() {
	for (int i = 1; i <= 12; ++i) {
		for (int j = 1; j <= 6; ++j) {
			printf("%c ", puyo[i][j]);
		}
		printf("\n");
	}
}
int main()
{

	for (int i = 1; i <= 12; ++i) {
		for (int j = 1; j <= 6; ++j) {
			scanf(" %c", &puyo[i][j]);
		}
	}

	while (1) {
		visit.clear();
		visit.resize(13, vector<int>(7, 0));
		flag = false;
		for (int i = 12; i > 0; --i) {
			for (int j = 1; j <= 6; ++j) {
				if (visit[i][j]) continue;
				if (puyo[i][j] == '.') continue;
				q.push({ i, j });
				visit[i][j] = 1;
				if (bfs())
					flag = true;
			}
		}
		if (!flag)
			break;
		else {
			ans++;
			update();
			print();
		}
	}
	printf("%d\n", ans);
}

