#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int n;
int table[1000][3];
vector<vector<int> > home;

int dp(int cur, int rgb) {

	int &ret = table[cur][rgb];
	if (cur >= n) return 0;

	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < 3; ++i) {
		if (i == rgb) continue;
		ret = min(ret, home[cur][i] + dp(cur + 1, i));
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	
	home.resize(n);
	memset(table, -1, sizeof(table));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			int rgb;
			cin >> rgb;
			home[i].push_back(rgb);
		}
	}
	for (int i = 0; i < 3; ++i)
		table[0][i] = min((int)1e9, home[0][i] + dp(1, i));
	int minV = 1e9;
	for (int i = 0; i < 3; ++i)
		minV = min(minV, table[0][i]);
	cout << minV;
}