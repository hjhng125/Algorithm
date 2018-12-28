#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;
vector<vector<pi> > adj;
vector<bool> visit;

int dfs(int cur) {
	
	visit[cur] = true;

	int maxDist = 0;
	for (int i = 0; i < adj[cur].size(); ++i) {
		int next = adj[cur][i].first;
		int weight = adj[cur][i].second;
		if (visit[next]) continue;
		maxDist = max(maxDist, weight + dfs(next));
	}
	return maxDist;
}
int main()
{
	int n;

	scanf("%d", &n);
	adj.resize(n + 1);

	for (int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	int maxDist = 0;
	for (int i = 1; i < adj.size(); ++i) {
		visit.clear();
		visit.resize(n + 1);
		maxDist = max(maxDist, dfs(i));
	}

	printf("%d", maxDist);
}