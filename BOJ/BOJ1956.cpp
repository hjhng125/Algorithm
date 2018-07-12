#include<cstdio>
#include<vector>
#include<algorithm>

#define INF 1e9
using namespace std;

typedef pair<int, int> pi;
int v, e;
int table[401][401];
int main()
{
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; ++j)
			table[i][j] = INF;
	}
	for (int i = 1; i <= e; ++i) {
		int sc, en, c;
		scanf("%d %d %d", &sc, & en, &c);
		table[sc][en] = c;
	}
	for (int k = 1; k <= v; ++k) {
		for (int i = 1; i <= v; ++i) {
			for (int j = 1; j <= v; ++j) 
				table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
		}
	}
	int ans = INF;
	for (int i = 1; i <= v; ++i) {
		ans = min(ans,table[i][i]);
	}
	if (ans == INF)
		ans = -1;
	printf("%d", ans);
}