#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>

using namespace std;

bool visit[101];
int main()
{
	int n, s ,d, m;
	vector<vector<int> > adj;
	scanf("%d", &n);
	scanf("%d %d", &s, &d);
	scanf("%d", &m);
	adj.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	queue<int> q;
	q.push(s);
	visit[s] = true;
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 1; i <= size; ++i) {
			int cur = q.front();
			q.pop();
			if (cur == d) {
				printf("%d", cnt);
				exit(0);
			}
			for (int next : adj[cur]) {
				if (visit[next]) continue;
				q.push(next);
				visit[next] = true;
			}
		}
		cnt++;
	}
	printf("-1");
}