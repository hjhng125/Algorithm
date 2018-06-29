#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 19998

using namespace std;

int n, m;
vector<vector<pair<int, int> > > adj;

int max_distance = 0;
void init() {
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < adj[i].size(); ++j)
			adj[i][j].second = 0;
	}
}
void dfs(int start, int dis) {
	
	if (start == 1 && dis != 0) {
		max_distance = max(dis, max_distance);
		return;
	}
	dis++;
	for (int i = 0; i < adj[start].size(); ++i) {
		if (adj[start][i].first && !adj[start][i].second) {
			adj[start][i].second = 1;
			for (int j = 0; j < adj[adj[start][i].first].size(); ++j) {
				if(start == adj[adj[start][i].first][j].first)
					adj[adj[start][i].first][j].second = 1;
			}	
			dfs(adj[start][i].first,dis);
		}
	}
}

void solution() {
	for (int i = 1; i <= m; ++i) {
		init();
		int dist = 0;
		dfs(i, dist);
	}
}

int main()
{
	int u, v;
	scanf("%d %d",&n,&m);
	adj.resize(m + 1);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(make_pair(v, 0));
		adj[v].push_back(make_pair(u, 0));
	}
	solution();

	printf("%d",max_distance);

	return 0;
}