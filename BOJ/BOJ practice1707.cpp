#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > adj;
vector<int> visit;
int n;

bool bfs(int s, int cnt) {

	queue<int> q;
	bool flag = false;
	q.push(s);
	visit[s] = cnt;

	while (!q.empty()) {
		int size = q.size();

		(cnt == 1) ? cnt++ : cnt--;
		for (int i = 0; i < size; ++i) {
			int cur = q.front();
			q.pop();
			for (auto next : adj[cur]) {
				if (visit[next]) {
					if (visit[next] != cnt) {
						flag = true;
						break;
					}
					else continue;
				}
				q.push(next);
				visit[next] = cnt;
			}
			if (flag) break;
		}
		if (flag) break;
	}
	return flag;
}
int main()
{
	scanf("%d", &n);

	while (n--) {
		int v, e;
		scanf("%d %d", &v, &e);

		if (v < 3 && e < 2) {
			printf("NO\n");
			continue;
		}
		adj.clear();
		adj.resize(v + 1);
		visit.clear();
		visit.resize(v + 1);

		while (e--) {
			int u, v;
			scanf("%d %d", &u, &v);

			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bool flag = false;
		for (int i = 1; i <= v; ++i) {
			if (!visit[i]) {
				if (bfs(i, 1)) {
					flag = true;
					break;
				}
			}
		}
		if (!flag) printf("YES\n");
		else printf("NO\n");
	}
}