#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
int n, m;
vector < vector< int > > adj;
vector<int> visit;
queue<int> q;

int main()
{
	int t;

	scanf("%d", &t);
	while (t > 0) {
		scanf("%d %d", &n, &m);
		adj.clear();
		visit.clear();
		adj.resize(n + 1);
		visit.resize(n + 1);
		for (int i = 1; i <= m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		q.push(1);
		int cnt = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (!visit[u]){
				visit[u] = 1;
				cnt++;
			}
			for (int i = 0; i < adj[u].size(); ++i) {
				int v = adj[u][i];
				if (!visit[v])
					q.push(v);
			}
		}
		printf("%d\n",cnt-1);
		t--;
	}
	return 0;
}