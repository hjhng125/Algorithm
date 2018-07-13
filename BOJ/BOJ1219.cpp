/**
Gee를 판별하기 위해선 음의 사이클을 판별한 후 
음의 사이클로 부터 목적지까지 갈 수 있는지 확인하여야 한다.
이러한 작업이 없을 시 정확한 Gee를 찾을 수 없음.
Cycle이 판별되었을 때 포함된 점들로부터 도착지에 갈 수 있는지 확인한다.
갈 수 있다면 Gee, 갈 수 없으면 벌 수 있는 돈의 최대값, 
도착지로 어느 점도 갈 수 없으면 gg
*/
#include<cstdio>
#include<vector>
#include<queue>

#define INF -1e9
using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
int n, sp, ep, m;
int s, e;
ll c;
vector<ll> profit;
vector<vector<pi> > adj;
vector<ll> dist;
vector<int> checkGee, visit;
queue<int> q;
int main()
{
	scanf("%d %d %d %d", &n, &sp, &ep, &m);
	profit.resize(n);
	adj.resize(n);
	dist.resize(n);
	checkGee.resize(n);
	visit.resize(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %lld", &s, &e, &c);
		adj[s].push_back(make_pair(e, -c));
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &profit[i]); 
		dist[i] = INF;
	}
	dist[sp] = profit[sp];

	bool flag = true;
	int cnt = n;
	while (flag && cnt != 0) {
		flag = false;
		for (int i = 0; i < n; ++i) {
			if (dist[i] == INF) continue;
			for (int j = 0; j < adj[i].size(); ++j) {
				int there = adj[i][j].first;
				if (dist[there] < adj[i][j].second + dist[i] + profit[there]) {
					dist[there] = adj[i][j].second + dist[i] + profit[there];
					flag = true;
					if (cnt == 1)
						checkGee[i] = 1;
				}
			}
		}
		cnt--;
	}

	for (int i = 0; i < checkGee.size(); ++i) {
		if(checkGee[i])
			q.push(i);
	}
	bool chk = false;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (visit[here]) continue;
		visit[here] = 1;
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			if (there == ep) {
				chk = true;
				break;
			}
			if (!visit[there])
				q.push(there); 
		}
		if (chk)
			break;
	}
	if (dist[ep] == INF) printf("gg");
	else if (chk) printf("Gee");
	else printf("%lld", dist[ep]);
}