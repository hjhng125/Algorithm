#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

typedef struct shark {
	int x, y, w, eat, m;
};
int n;
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { 1, 0, 0, -1 };
vector<vector<int> > map, visit;
queue<shark> q;
int main()
{
	scanf("%d", &n);
	map.resize(n + 1, vector<int>(n + 1));
	visit.resize(n + 1, vector<int>(n + 1));

	int x, y;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9)
				q.push({j, i, 2, 0, 0 });
		}
	}
	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int cw = q.front().w;
		int ce = q.front().eat;
		int cm = q.front().m;
		q.pop();
		
		if (cw > map[cy][cx]) {
			map[cy][cx] = 0;
			ce++;
			if (ce == cw)
				cw++;
			q.front().m = cm;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
			if (map[nx][ny] > cw) continue;
			q.push({ nx,ny,cw,ce, cm });
		}
		cm++;
	}

}