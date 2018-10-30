#include<cstdio>
#include<string>

using namespace std;

int n, k;
int map[501][501], visit[501], b_match[501];
bool dfs(int from) {
	if (visit[from]) return false;
	visit[from] = true;
	for (int i = 1; i <= n; ++i) {
		int next;
		if (map[from][i]) {
			next = i;
			if (!b_match[next] || dfs(b_match[next])) {
				b_match[next] = from;
				return true;
			}
		}
	}
	return false;
}
int match() {
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		fill(visit, visit + n + 1, 0);
		if (dfs(i))
			ans++;
	}
	return ans;
}
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; ++i) {
		int r, c;
		scanf("%d %d", &r, &c);
		map[r][c] = 1;
	}
	printf("%d", match());
}