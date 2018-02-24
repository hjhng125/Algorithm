#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
#define MAX 52
#define INF 1e9 + 1

using namespace std;

int n;
vector<int> adj[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int parent[MAX];

int cTOi(char ch){
	if (ch <= 'Z') return ch - 'A';
	return ch - 'a' + 26;
}
int residual(int here, int there){
	return c[here][there] - f[here][there];
}
int edmonds_karp(int start, int end){
	int total = 0;
	while (true){
		memset(parent,-1,sizeof(parent));
		queue<int> q;
		q.push(start);
		parent[start] = start;

		while (!q.empty() && parent[end] == -1){
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++){
				int there = adj[here][i];
				if (residual(here, there) > 0 && parent[there] == -1){
					parent[there] = here;
					q.push(there);
					if (there == end) break;
				}
			}
		}
		if (parent[end] == -1) break;
		int btn = INF; 
		for (int i = end; i != start; i = parent[i])
			btn = min(residual(parent[i], i), btn);
		for (int i = end; i != start; i = parent[i]){
			f[parent[i]][i] += btn;
			f[i][parent[i]] -= btn;
		}
		total += btn;
	}
	return total;
}
int main()
{
	memset(c,0,sizeof(c));
	memset(f, 0, sizeof(f));

	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		char cu, cv;
		int w;
		scanf(" %c %c %d", &cu, &cv, &w);
		int u, v;
		u = cTOi(cu);
		v = cTOi(cv);
		c[u][v] += w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	printf("%d\n", edmonds_karp(0, 'Z' - 'A'));

	return 0;
}