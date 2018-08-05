#include<iostream>
#include<vector>
#include<queue>

#define MAX 200
#define INF 1e9 + 1

using namespace std;

int n, c[MAX][MAX], f[MAX][MAX];
vector<vector<int> > adj;

int cToI(char c) {
	if (c <= 'Z') {
		return c - 'A';
	}
	return c - 'a' + 26;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	adj.resize(MAX);
	for (int i = 0; i < n; ++i) {
		char U, V;
		int b;
		cin >> U >> V >> b;
		int u = cToI(U);
		int v = cToI(V);
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] += b;
		c[v][u] += b;
	}
	int S = cToI('A');
	int T = cToI('Z');
	int total = 0;
	while (1) {
		vector<int> prev(MAX, -1);
		queue<int> q;
		q.push(S);
		prev[S] = S;
	
		while (!q.empty() && prev[T] == -1) {
			int here = q.front();
			q.pop();
			for (int next : adj[here]) {
				if (c[here][next] - f[here][next] > 0 && prev[next] == -1) {
					prev[next] = here;
					q.push(next);
					
				}
			}
		}
		if (prev[T] == -1)
			break;
		int minFlow = INF;
		for (int i = T; i != S; i = prev[i])
			minFlow = min(minFlow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = T; i != S; i = prev[i]) {
			f[prev[i]][i] += minFlow;
			f[i][prev[i]] -= minFlow;
		}
		total += minFlow;
	}
	cout << total << "\n";

	return 0;
}