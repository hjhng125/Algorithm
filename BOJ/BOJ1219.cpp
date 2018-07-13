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
	else if (chk) printf("gee");
	else printf("%lld", dist[ep]);
}