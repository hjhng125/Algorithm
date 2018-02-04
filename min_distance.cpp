#include<cstdio>
#include<vector>
#include<queue>
#define INF 1e9+1

using namespace std;

typedef pair<int, int> pii;
struct comp{
	bool operator() (pii p1, pii p2){
		return p1.second > p2.second;
	}
};
vector<vector<pii> > adj;
vector<int> dis;
priority_queue<pii ,vector<pii>, comp> pq;
int vt, e;
int s;
int u, v, w;
void init();
void dijkstra();
int main()
{
	scanf("%d %d",&vt, &e);
	scanf("%d",&s);

	adj.resize(vt + 1);
	dis.resize(vt + 1,INF);

	for (int i = 0; i < e; i++){
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v,w));
	}
	init();
	dijkstra();
	for (int i = 1; i <= vt; i++){
		if (dis[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dis[i]);
	}
	return 0;
}
void init()
{
	dis[s] = 0;
	for (int i = 1; i <= vt; i++){
		pq.push(make_pair(i,dis[i]));
	}
}
void dijkstra()
{
	pii minDist;
	int u, d;
	while (!pq.empty()){ // queue가 빌 때까지
		minDist = pq.top(); // queue안의 최소값
		pq.pop();
		u = minDist.first;
		d = minDist.second;
		if (d > dis[u]) // dis 벡터보다 들어올 값이 크다면 pass
			continue;
		for (int i = 0; i < adj[u].size(); i++){ // 인접 노드 확인		
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if (w + dis[u] < dis[v]){ // 인접노드의 정보로 dis벡터 최신화
				dis[v] = w + dis[u];
				pq.push(make_pair(v, dis[v]));
			}
		}
	}
}
