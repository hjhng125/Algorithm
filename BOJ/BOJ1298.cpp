#include<cstdio>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<int> b, visit;

int dfs(int here) {
	if (visit[here]) return 0;
	visit[here] = 1;
	for (int i = 0; i <= adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	b.resize(m + 1);

	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	int result = 0;
	for (int i = 1; i <= n; ++i) {
		visit.clear();
		visit.resize(n + 1, 0);
		if(dfs(i))
			result++;
	}
	printf("%d",result);
}