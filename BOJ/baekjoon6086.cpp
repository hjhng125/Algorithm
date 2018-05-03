#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>

#define MAX 52
#define INF 1e9 + 1
using namespace std;

int n;
vector<int> adj[MAX];
int parent[MAX];
int c[MAX][MAX], f[MAX][MAX];

char cToI(char ch){
	if (ch <= 'Z') return ch - 'A';
	return ch - 'a' + 26;
}
int residual(int here, int there){
	return c[here][there] - f[here][there];
}
int maximum_flow(int start, int end){
	int total = 0;
	while (true){
		memset(parent,-1,sizeof(parent));
		parent[start] = start;
		queue<int> q;
		q.push(start);

		while (!q.empty() && parent[end] == -1){
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); ++i){
				int there = adj[here][i];
				if (residual(here, there) > 0 && parent[there] == -1){
					parent[there] = here;
					q.push(there);
					if (there == end) break;
				}
			}
		}
		if (parent[end] == -1) break;
		int minFlow = INF;
		for (int i = end; i != start; i = parent[i])
			minFlow = min(residual(parent[i], i), minFlow);
		for (int i = end; i != start; i = parent[i]){
			f[parent[i]][i] += minFlow;
			f[i][parent[i]] -= minFlow;
		}
		total += minFlow;
	}
	return total;
}
int main()
{
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));

	scanf("%d%*c", &n);
	for (int i = 0; i < n; ++i){
		char cu, cv; 
		int w;
		scanf("%c %c %d%*c", &cu, &cv, &w);
		int u, v;
		u = cToI(cu);
		v = cToI(cv);
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] += w;
	}
	printf("%d",maximum_flow(0,'Z' - 'A'));
}