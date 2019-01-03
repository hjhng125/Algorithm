#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int> > adj, team;
bool visit[101];
int n, hn, flag = 1;
queue<int> q;

void bfs(int s) {
	q.push(s);
	visit[s] = true;
	team[flag].push_back(s);
	while (!q.empty()) {

		int size = q.size();
		
			int cur = q.front(); q.pop();
			for (int next : adj[cur]) {
				if (visit[next]) continue;
				q.push(next);
				visit[next] = true;
				team[flag].push_back(next);
			}
		}
	}

}
int main()
{
	scanf("%d", &n);
	adj.resize(n + 1);
	team.resize(3);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &hn);
		for (int j = 1; j <= hn; ++j) {
			int h;
			scanf("%d", &h);
			adj[i].push_back(h);
			adj[h].push_back(i);
		}
	}

	for (int i = 1; i <= n; ++i)
		if(!visit[i]) bfs(i);
	
	for (int i = 1; i <= 2; ++i)
		sort(team[i].begin(), team[i].end());

	for (int i = 1; i <= 2; ++i) {
		printf("%d\n", team[i].size());
		for (int j = 0; j < team[i].size(); ++j) 
			printf("%d ", team[i][j]);
		printf("\n");
	}
}