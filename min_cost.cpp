#include<cstdio>
#include<vector>
#include<queue>
#define INF 1e9+1

using namespace std;
typedef pair<int, int> pii;
struct comp {
	bool operator() (pii p1, pii p2){
		return p1.second > p2.second;
	}
};
vector<vector<pii> > adj;
vector<int> dist;
priority_queue<pii, vector<pii>, comp> pq;

void init();
void dijkstra();

int n, m;
int u, v, w;
int start, dest;

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);

	adj.resize(n + 1);
	dist.resize(n + 1, INF);
	for (int i = 1; i <= m; ++i){
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	scanf("%d %d", &start, &dest);
	init();
	dijkstra();
	printf("%d", dist[dest]);

	return 0;
}
void init()
{
	dist[start] = 0;
	for (int i = 1; i <= n; ++i)
		pq.push(make_pair(i, dist[i]));
}
void dijkstra()
{
	int v_u, v_d, v_v, v_w; // 시작점,시작점의 cost, 갈곳, 갈곳의 cost

	while (!pq.empty()){
		v_u = pq.top().first;
		v_d = pq.top().second;
		pq.pop();
		if (v_d > dist[v_u])
			continue;
		for (int i = 0; i < adj[v_u].size(); ++i){
			v_v = adj[v_u][i].first;
			v_w = adj[v_u][i].second;

			if (dist[v_v] > v_w + dist[v_u]){
				dist[v_v] = v_w + dist[v_u];
				pq.push(make_pair(v_v, dist[v_v]));
			}
		}
	}
}