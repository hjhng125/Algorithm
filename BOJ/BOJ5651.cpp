#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, test;
vector<vector<int> > adj;
queue<int> q;

int main()
{

	scanf("%d", &test);
	while (test > 0) {
		vector<vector<int> > c(n + 1, vector<int>(n + 1, 0));
		vector<vector<int> > flow(n + 1, vector<int>(n + 1, 0));
		vector<pair<int, int> > vt;
		scanf("%d %d", &n, &m);
		adj.clear();
		adj.resize(n + 1);
		for (int i = 1; i <= m; ++i) {
			int f, t, b;
			scanf("%d %d %d", &f, &t, &b);
			adj[f].push_back(t);
			adj[t].push_back(f);
			c[f][t] = b;
			vt.push_back({ f, t });
		}

		int ans = 0;
		while (1) {
			vector<int> visit(n + 1, -1);
			q.push(1);
			while (!q.empty()) {
				int here = q.front();
				q.pop();
				for (int next : adj[here]) {
					if (c[here][next] - flow[here][next] > 0 && visit[next] == -1) {
						q.push(next);
						visit[next] = here;
						
					}
				}
			}
			if (visit[n] == -1)
				break;
			int minFlow = 1e9;
			for (int i = n; i != 1; i = prev[i]) {
				minFlow = min(c[prev[i]][i] - flow[prev[i]][i], minFlow);
			}
			for (int i = n; i != 1; i = prev[i]) {
				flow[prev[i]][i] += minFlow;
				flow[i][prev[i]] -= minFlow;
			}
		}
		for (int i = 0; i < vt.size(); ++i) {
			int st = vt[i].first;
			int dest = vt[i].second;
			vector<int> visit(n + 1, -1);
			queue<int> q1;
			q1.push(st);
			while (!q1.empty() && visit[dest] == -1) {
				int here = q1.front();
				q1.pop();
				for (auto next : adj[here]) {
					if (c[here][next] - flow[here][next] > 0 && visit[next] == -1) {
						visit[next] = here;
						q1.push(next);
					}
				}
			}
			if (visit[dest] == -1)
				ans++;
		}

		printf("%d\n", ans);
		test--;
	}
}