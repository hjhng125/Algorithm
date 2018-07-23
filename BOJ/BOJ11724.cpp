#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > adj;
vector<int> visit;
queue<int> q;
int main()
{
	int n, m;

	scanf("%d %d" , &n, &m);
	adj.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int begin, end;
		scanf("%d %d", &begin, &end);
		adj[begin].push_back(end);
		adj[end].push_back(begin);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!visit[i]) {
			q.push(i);
			visit[i] = 1;
			cnt++;
		}
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i];
				if (!visit[there]) {
					q.push(there);
					visit[there] = 1;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}