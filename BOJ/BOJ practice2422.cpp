#include<iostream>
#include<vector>

using namespace std;

int n, m;
bool comb[201][201];
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		comb[a][b] = true;
		comb[b][a] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = j + 1; k <= n; ++k) {
				if (comb[i][j] || comb[j][k] || comb[k][i]) continue;
				cnt++;
			}
		}
	}
	cout << cnt;
}