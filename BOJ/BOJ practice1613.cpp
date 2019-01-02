#include<cstdio>
#include<algorithm>
#define INF 1e9

using namespace std;

int n, k, s;
int map[401][401];

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = INF;
		}
	}
}
int main()
{
	scanf("%d %d", &n, &k);
	
	init();
	for (int i = 1; i <= k; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);	
		map[u][v] = 1;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (map[i][k] + map[k][j] < INF) map[i][j] = 1;
			}
		}
	}
	scanf("%d", &s);
	for (int i = 1; i <= s; ++i) {
		int u, v, result;
		scanf("%d %d", &u, &v);
		
		if (map[u][v] == 1) result = -1;
		else if (map[v][u] == 1) result = 1;
		else result = 0;
		printf("%d\n", result);
	}
}