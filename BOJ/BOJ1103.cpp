#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char arr[60][60];
int visit[60][60], dp[60][60];
int n, m;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

int dfs(int curX, int curY) {
	
	if (curX <= 0 || curX > m) return 0;
	if (curY <= 0 || curY > n) return 0;
	if (arr[curY][curX - 1] == 'H') return 0;
	if (visit[curY][curX]) {
		printf("-1");
		exit(0);
	}
	
	if (dp[curY][curX] != -1)
		return dp[curY][curX];
	
	visit[curY][curX] = 1;

	int tmp = arr[curY][curX - 1] - '0';
	for (int i = 0; i < 4; i++) {
		int nX = curX + dx[i] * tmp;
		int nY = curY + dy[i] * tmp;
		dp[curY][curX] = max(dp[curY][curX], dfs(nX, nY) + 1);
	}
	visit[curY][curX] = 0;

	return dp[curY][curX];
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%s", arr[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", dfs(1, 1));
}