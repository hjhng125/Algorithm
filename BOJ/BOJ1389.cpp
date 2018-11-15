#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<int> arr;
int main()
{
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	arr.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int minV = 1e9, min_idx;
	for (int i = 1; i <= n; ++i) {
		queue<int> q;
		vector<int> visit(n + 1, -1);
		q.push(i);
		int cnt = 0;
		visit[i] = cnt;
		while (!q.empty()) {
			int size = q.size();
			for (int k = 0; k < size; ++k) {
				int cur = q.front();
				q.pop();

				for (int j = 0; j < adj[cur].size(); ++j) {
					int next = adj[cur][j];
					if (visit[next] >= 0) continue;
					q.push(next);
					visit[next] = cnt+1;
				}
			}
			cnt++;
		}
		int ans = 0;
		for (int k = 1; k <= n; ++k) {
			ans += visit[k];
		}
		if (minV > ans) {
			minV = ans;
			min_idx = i;
		}
	}
	printf("%d", min_idx);
}