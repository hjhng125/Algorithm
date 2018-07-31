#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX_V 202

using namespace std;

int c[MAX_V][MAX_V], f[MAX_V][MAX_V], cost[MAX_V][MAX_V];
int n, m;
int a;
int main()
{
	scanf("%d %d", &n, &m);
	int S = 0, T = n + m + 1;
	vector<vector<int> > adj(T + 1);

	for (int i = m + 1; i < T; ++i) {
		scanf("%d", &a);
		adj[i].push_back(T);
		adj[T].push_back(i);
		c[i][T] = a;
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &a);
		adj[S].push_back(i);
		adj[i].push_back(S);
		c[S][i] = a;
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = m + 1; j < T; ++j) {
			scanf("%d", &a);
			if (a != 0) {
				adj[i].push_back(j);
				adj[j].push_back(i);
				c[i][j] = a;
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = m + 1; j < T; ++j) {
			scanf("%d", &a);
			cost[i][j] = a;
			cost[j][i] = -a;
		}
	}
	int result = 0, cnt = 0;
	while (1) {
		queue<int> q;
		vector<int> d(T + 1, 1e9);
		vector<int> prev(T + 1, -1);
		vector<bool> inQ(T + 1, false);
		prev[S] = S;
		d[S] = 0;
		q.push(S);
		inQ[S] = true;
		while (!q.empty()) {
			int here = q.front(); 
			q.pop();
			inQ[here] = false;
			for (auto next : adj[here]) {
				if (c[here][next] - f[here][next] > 0 && d[next] > d[here] + cost[here][next]) {
					prev[next] = here;
					d[next] = d[here] + cost[here][next];
					if (!inQ[next]) {
						q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if (prev[T] == -1)
			break;

		int flow = 1e9;
		for (int i = T; i != S; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}
		for (int i = T; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
			result += flow * cost[prev[i]][i];
		}
		cnt += flow;
	}

	printf("%d\n%d", cnt, result);
	return 0;
}