#include<cstdio>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;

typedef struct node {
	int x, y, cnt;
};
struct comp {
	bool operator()(node a, node b) {
		return a.cnt > b.cnt;
	}
};
int miro[101][101];
int dist[101][101];
priority_queue<node, vector<node>, comp> pq;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m, n;
int main()
{
	scanf("%d %d", &m, &n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf(" %1d", &miro[i][j]);
			dist[i][j] = INF;
		}
	}
	dist[1][1] = 0;
	pq.push({ 1, 1, 0 });
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cnt = pq.top().cnt;
		pq.pop();
		for (int k = 0; k < 4; ++k) {
			int nexty = y + dy[k];
			int nextx = x + dx[k];
			
			if ((nexty >= 1 && nexty <= n) && (nextx >= 1 && nextx <= m)) {
				if (dist[nexty][nextx] > dist[y][x] + miro[nexty][nextx]) {
					dist[nexty][nextx] = dist[y][x] + miro[nexty][nextx];
					pq.push({nextx, nexty, dist[nexty][nextx]});
				}
			}
		}
	}

	printf("%d", dist[n][m]);
	return 0;
}