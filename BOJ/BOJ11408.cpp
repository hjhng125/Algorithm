#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int cost[802][802], c[802][802], f[802][802];

int main()
{
	scanf("%d %d", &n, &m);
	int S = 0, T = n + m + 1;
	vector<vector<int> > adj(T + 1);
	for (int i = 1; i <= n; ++i) {
		//S와 일을 이어줌
		adj[S].push_back(i);
		adj[i].push_back(S);
		c[S][i] = 1;
		int jNum;
		scanf("%d", &jNum);
		for (int j = 1; j <= jNum; ++j) {
			int jn, s;
			// 일과 급여를 이어줌
			scanf("%d %d", &jn, &s);
			adj[i].push_back(jn + n);
			adj[jn + n].push_back(i);
			c[i][jn + n] = 1;
			cost[i][jn + n] = s;
			cost[jn + n][i] = -s;
		}
	}
	for (int i = n + 1; i < T; ++i) {
		// 급여와 일 개수 이어줌
		adj[i].push_back(T);
		adj[T].push_back(i);
		c[i][T] = 1;
	}

	int result = 0, cnt = 0;
	while (1) {
		// prev : 지나온 경로를 저장
		vector<int> prev(T + 1, -1);
		// dist : 경로의 최단 거리
		vector<int> dist(T + 1, 1e9);
		// inQ : queue에 무엇이 들어가있는지 저장
		vector<bool> inQ(T + 1, false);
		queue<int> q;

		prev[S] = S;
		q.push(S);
		inQ[S] = true;
		dist[S] = 0;
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			inQ[here] = false;
			for (auto next : adj[here]) {
				// 증가경로를 판별하며 최단거리를 측정
				if (c[here][next] - f[here][next] > 0 && dist[next] > dist[here] + cost[here][next]) {
					dist[next] = dist[here] + cost[here][next];
					prev[next] = here;
					// next가 q에 없다면 넣어준다.
					if (!inQ[next]) {
						q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		// T로 가는 증가경로가 없으면 break;
		if (prev[T] == -1)
			break;

		for (int i = T; i != S; i = prev[i]) {
			result += cost[prev[i]][i];
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
		cnt++;
	}

	printf("%d\n%d\n", cnt, result);
	return 0;
}