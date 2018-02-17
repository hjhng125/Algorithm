#include<cstdio>
#include<vector>
#include<queue>

#define INF 1e9+1
using namespace std;

void init(int);
void belman();
int n, m;
int u, v, w;
int s;
vector<vector<pair<int, int> > > adj;
vector<int> d;
int main()
{
	scanf("%d %d", &n, &m);
	init(1);
	for (int i = 0; i < m; ++i){
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	belman();
	return 0;
}
void belman()
{
	bool chk = true;
	int cnt = n;

	while (chk && cnt != 0){
		chk = false;
		for (int i = 1; i <= n; ++i){
			for (int j = 0; j < adj[i].size(); ++j){
				int u = adj[i][j].first;
				if (d[u] > adj[i][j].second + d[i]){
					d[u] = adj[i][j].second + d[i];
					chk = true;
				}
			}
		}
		cnt--;
	}
	if (chk)
		printf("-1\n");
	else{
		for (int i = 2; i <= n; ++i){
			if (d[i] == INF) printf("-1\n");
			else printf("%d\n", d[i]);
		}
	}
}
void init(int start)
{
	adj.resize(n + 1);
	d.resize(n + 1, INF);
	d[start] = 0;
}