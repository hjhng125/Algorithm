#include<cstdio>
#include<vector>
#include<queue>
#define INF 1e9+1
using namespace std;

void init(int);
void belman();
int t, n, m, w;
int s, e, time;

vector<vector<pair<int, int> > > road;
vector<int> dis;
int main()
{
	scanf("%d", &t);
	for (int j = 0; j < t; ++j){
		
		scanf("%d %d %d", &n, &m, &w);
		dis.resize(n + 1);
		road.resize(n + 1);
		for (int i = 0; i < m; ++i){
			scanf("%d %d %d", &s, &e, &time);
			road[s].push_back(make_pair(e, time));
			road[e].push_back(make_pair(s, time));
		}
		for (int i = 0; i < w; ++i){
			scanf("%d %d %d", &s, &e, &time);
			road[s].push_back(make_pair(e, -time));
		}
		init(1);
		belman();
		
		dis.clear();
		road.clear();
	}
	return 0;
}
void init(int start)
{
	for (int i = 1; i <= n; ++i){
		if (i == start)
			dis[i] = 0;
		else
			dis[i] = INF;
	}
}
void belman()
{
	int count = n;
	bool flag = true;
	while (count != 0 && flag){
		flag = false;
		for (int i = 1; i <= n; ++i){
			for (int j = 0; j < road[i].size(); ++j){
				int there = road[i][j].first;
				if (dis[there] > road[i][j].second + dis[i]){
					dis[there] = road[i][j].second + dis[i];					
					flag = true;
				}
			}
		}
		count--;
	}
	if (count == 0)
		printf("YES\n");
	else
		printf("NO\n");
}