#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 2002
#define S 0
#define T n + m + 1
using namespace std;

int c[MAX][MAX];
int n, m;
int num;
vector<vector<int> > adj;
queue<int> q;
int main()
{
	scanf("%d %d", &n, &m);
	adj.resize(T + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &num);
		for (int j = 1; j <= num; ++j) {
			int a;
			scanf("%d", &a);
			adj[i].push_back(n + a);
			adj[n + a].push_back(i);
			c[i][n + a] = 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		c[S][i] = 2;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for (int i = n + 1; i <= n + m; ++i) {
		c[i][T] = 1;
		adj[i].push_back(T);
		adj[T].push_back(i);
	}
	int ans = 0;
	while (1) {
		int prev[MAX];

		fill(prev, prev + T + 1, -1);
		q.push(S);
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int next : adj[here]) {
				//여기서 prev는 visit 과 같은 역할을 한다.
				if (c[here][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = here;
					if (next == T)
						break;
				}
			}
		}
		if (prev[T] == -1)
			break;
		ans++;
		for (int i = T; i != S; i = prev[i]) {
			c[prev[i]][i]--;
			c[i][prev[i]]++;
		}
	}
	printf("%d\n",ans);
}