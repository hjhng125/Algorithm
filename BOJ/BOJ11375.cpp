#include<cstdio>
#include<vector>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<bool> visit;
vector<int> b_match;

bool dfs(int here) {
	if (visit[here])
		return false;
	visit[here] = true;

	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!b_match[there] || dfs(b_match[there])) {
			b_match[there] = here;
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	visit.resize(n + 1);
	b_match.resize(m + 1);

	for (int idx = 1; idx <= n; ++idx) {
		int i;
		scanf("%d", &i);
		for (int j = 1; j <= i; ++j) {
			int dest;
			scanf("%d", &dest);
			adj[idx].push_back(dest);
		}
	}
	int result = 0;
	for (int i = 1; i <= n; ++i) {
		visit.clear();
		visit.resize(n + 1, false);
		if (dfs(i))
			result++;
	}

	printf("%d", result);
}