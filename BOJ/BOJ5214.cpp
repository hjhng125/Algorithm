#include<cstdio>
#include<vector>
#include<queue>

#define INF 1e9
using namespace std;

int n, k, m;
vector<vector<int> > adj;
vector<int> dist_table;
queue<pair<int, int> > q;

int main()
{
	scanf("%d %d %d", &n, &k,& m);
	adj.resize(n + m + 1);
	dist_table.resize(n + m + 1, INF);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= k; ++j) {
			int station;
			scanf("%d", &station);
			adj[n + i].push_back(station);
			adj[station].push_back(n + i);
		}
	}
	q.push(make_pair(1, 1));
	dist_table[1] = 1;

	while (!q.empty()) {
		int cur = q.front().second;
		int cost = q.front().first;
		q.pop();
		if (dist_table[cur] < cost) continue;
		for (int next : adj[cur]) {
			int ncost = cost + 1;
			if (dist_table[next] > ncost) {
				dist_table[next] = ncost;
				q.push(make_pair(ncost, next));
			}
		}
	}
	if (dist_table[n] == INF)
		printf("-1");
	else
		printf("%d", (dist_table[n] + 1) / 2);
	return 0;
}