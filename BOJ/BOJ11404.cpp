#include<iostream>
#include<vector>
#include<algorithm>

#define INF 1e9
using namespace std;

typedef pair<int, int> pi;
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> m;
	vector<vector<int> > dist(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		if (dist[u][v] != INF)
			dist[u][v] = min(dist[u][v], c);
		else
			dist[u][v] = c;
	
	}
	
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j)
					dist[i][j] = INF;
				else if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == INF)
				cout << 0 << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}