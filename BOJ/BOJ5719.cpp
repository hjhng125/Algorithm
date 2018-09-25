#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;
int n, m;
vector<vector<pi> > adj, back_adj;
vector<int> cost_table;
int s, e;
struct cmp {
	bool operator()(pi a, pi b) {
		return a.second > b.second;
	}
};

void dijkstra() {
	priority_queue<pi, vector<pi>, cmp> pq;
	pq.push(make_pair(s, 0));
	cost_table = vector<int>(n, 1e9);
	cost_table[s] = 0;

	while (!pq.empty()) {
		pi here = pq.top();
		pq.pop();

		for (int i = 0; i < adj[here.first].size(); ++i) {
			int next = adj[here.first][i].first;
			int dist = adj[here.first][i].second;

			if (dist == -1)
				continue;
			if (cost_table[next] > here.second + dist) {
				cost_table[next] = here.second + dist;
				pq.push(make_pair(next, cost_table[next]));
			}
		}
	}
}

void update() {
	queue<int> q;
	q.push(e);
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (here == s) continue;

		for (auto next : back_adj[here]) {
			int vtx = next.first;
			int cost = next.second;

			if (cost_table[here] == cost_table[vtx] + cost) {
				for (int i = 0; i < adj[vtx].size(); ++i) {
					if (here == adj[vtx][i].first) {
						adj[vtx][i].second = -1;
					}
				}
				q.push(vtx);
			}
		}
	}
}
int main()
{
	while (true) {
	
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;

		adj.resize(n);
		back_adj.resize(n);
		
		scanf("%d %d", &s, &e);

		for (int i = 1; i <= m; ++i) {
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			adj[u].push_back(make_pair(v, p));
			back_adj[v].push_back(make_pair(u, p));
		}

		dijkstra();
		update();
		dijkstra();

		if (cost_table[e] == 1e9) printf("-1\n");
		else printf("%d\n", cost_table[e]);

		adj.clear();
		back_adj.clear();
		cost_table.clear();
	}
}