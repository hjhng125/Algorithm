#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n, k, s;
vector<vector<int > > adj;
bool visit[401][401];

void bfs(int u, int v) {
	queue<int> q;
	q.push(v);
	visit[u][v] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			if (visit[u][next]) continue;
			q.push(next);
			visit[u][next] = true;
		}
	}
}
int main()
{
	scanf("%d %d", &n, &k);
	adj.resize(n + 1);

	for (int i = 1; i <= k; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= k; ++i) bfs(i, i);
	
	scanf("%d", &s);
	for (int i = 1; i <= s; ++i) {
		int u, v, result;
		scanf("%d %d", &u, &v);
		if (visit[u][v]) result = -1;
		else if (visit[v][u]) result = 1;
		else result = 0;
		
		printf("%d\n", result);
	}
}