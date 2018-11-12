#include<cstdio>
#include<vector>

#define INF 1e9
using namespace std;

typedef struct node {
	int to, weight;
};
int n, m;
int dist[501];
vector<vector<node> > adj;
int main()
{
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ v,w });
	}
	fill(dist + 1, dist + n + 1, INF);
	dist[1] = 0;

	bool flag = false;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < adj[i].size(); ++j) {
				int next = adj[i][j].to;
				int nextW = adj[i][j].weight;
				if (dist[next] > dist[i] + nextW && dist[i] != INF) { // INF와 음의 간선의 relax를 체크해야한다.
					dist[next] = dist[i] + nextW;
		
					if (k == n) flag = true;
				}
			}
		}
	}
	if (flag) printf("-1\n");
	else {
		for (int i = 2; i <= n; ++i) {
			if (dist[i] == INF) printf("-1\n");
			else printf("%d\n",dist[i]);
		}
	}
}