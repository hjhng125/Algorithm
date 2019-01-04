#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<limits>

using namespace std;

typedef struct NODE {
	int x, y, curBeer;
}Node;
int t, n;
bool visit[101];

double cal_distance(Node a, Node b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
bool bfs(vector<Node> adj) {
	queue<Node> q;
	q.push(adj[0]);
	visit[0] = true;
	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		cur.curBeer = 20;

		if (cur.x == adj[n + 1].x && cur.y == adj[n + 1].y) return true;
		for (int next = 1; next < adj.size(); ++next) {
			if (visit[next]) continue;
			if (cur.curBeer < cal_distance(cur, adj[next]) / 50) continue;
			q.push(adj[next]);
			visit[next] = true;
		}
	}
	return false;
}
int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		
		vector<Node> adj(n + 2);
		fill(visit + 0, visit + (n + 2), 0);
		for (int i = 0; i <= n+1; ++i) 
			scanf("%d %d", &adj[i].x, &adj[i].y);
	
		printf(bfs(adj) == false ? "sad\n" : "happy\n");		
	}
}