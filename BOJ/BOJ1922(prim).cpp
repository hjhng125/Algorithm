#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pi;
int n, m;
vector<vector<pi> > MST;
vector<int> visit;
priority_queue<pi, vector<pi>, greater<pi> > q;
int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	MST.resize(n + 1);
	visit.resize(n + 1);

	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		MST[a].push_back(make_pair(c, b));
		MST[b].push_back(make_pair(c, a));
	}

	q.push({ 0, 1 });
	int ans = 0;
	while (!q.empty()) {
		int here = q.top().second;
		int here_cost = q.top().first;
		q.pop();

		if (visit[here]) continue;
		
		ans += here_cost;
		visit[here] = 1;
		for (int i = 0; i < MST[here].size(); ++i) {
			int there = MST[here][i].second;
			int there_cost = MST[here][i].first;
			if (!visit[there])
				q.push({ there_cost, there });
		}
	}
	printf("%d", ans);
	return 0;
}