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
	while (!pq.empty()){ // queue�� �� ������
		minDist = pq.top(); // queue���� �ּҰ�
		pq.pop();
		u = minDist.first;
		d = minDist.second;
		if (d > dis[u]) // dis ���ͺ��� ���� ���� ũ�ٸ� pass
			continue;
		for (int i = 0; i < adj[u].size(); i++){ // ���� ��� Ȯ��		
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if (w + dis[u] < dis[v]){ // ��������� ������ dis���� �ֽ�ȭ
				dis[v] = w + dis[u];
				pq.push(make_pair(v, dis[v]));
			}
		}
	}
}
