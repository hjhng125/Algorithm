#include<cstdio>
#include<vector>
#include<queue>
#define INF 1e9+1
using namespace std;

void init();
void floyd();

vector<vector<pair<int,int> > > adj;
vector<vector<int> > dis;
int n, bus;
int u, v, w;
int main()
{
	scanf("%d", &n);
	scanf("%d", &bus);
	init();
	for (int i = 0; i < bus; ++i){
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	floyd();

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
			printf("%d ",dis[i][j]);
		printf("\n");
	}
	return 0;
}
void init()
{
	adj.resize(n + 1);
	for (int i = 0; i <= n; ++i){
		vector<int> ele;
		ele.resize(n + 1 , INF);
		dis.push_back(ele);
	}
	for (int i = 1; i <= n; ++i)
		dis[i][i] = 0;
}
void floyd()
{
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < adj[i].size(); ++j){
			int there = adj[i][j].first;
			if (!dis[i][there])
				dis[i][there] = adj[i][j].second;
			else{
				if (dis[i][there] > adj[i][j].second)
					dis[i][there] = adj[i][j].second;
			}
		}
	}
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
}