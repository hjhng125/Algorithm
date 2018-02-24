#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(int);
void BFS(int);
vector<vector<int> > adj;
vector<int> visited;
queue<int> q;
int n, m, v;
int start, dest;
int main()
{
	scanf("%d %d %d", &n, &m, &v);
	visited.resize(n + 1);
	adj.resize(n + 1);

	for (int i = 0; i < m; ++i){
		scanf("%d %d", &start, &dest);
		adj[start].push_back(dest);
		adj[dest].push_back(start);
	}
	for (int i = 1; i <= n; ++i){
		sort(adj[i].begin(), adj[i].end());
	}
	DFS(v);
	visited.clear();
	visited.resize(n + 1);
	printf("\n");
	BFS(v);

	return 0;
}
void DFS(int s)
{
	visited[s] = 1;
	printf("%d ", s);
	for (int i = 0; i < adj[s].size(); ++i){
		int dest = adj[s][i];
		if (!visited[dest])
			DFS(dest);
	}
}
void BFS(int s){
	visited[s] = 1;
	q.push(s);
	while (!q.empty()){
		s = q.front();
		for (int i = 0; i < adj[s].size(); ++i){
			int dest = adj[s][i];
			if (!visited[dest]){
				visited[dest] = 1;
				q.push(dest);
			}
		}
		q.pop();
		printf("%d ", s);
	}
}