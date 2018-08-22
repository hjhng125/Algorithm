#include<cstdio>
#include<cstring>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[501][501];
int check[501][501];
int n, m;
long ans;

int dfs(int x, int y) {

	// -1과 0으로 구분을 지어줌으로써 
	// 이미 가보았던 지점에서 더이상 경로가 없는 지점을 찾을 수 있고,
	// 방문하지 않은 지점과 구분이 가능하다.

	// 방문 해봤다면 그 곳에 저장된 값 리턴
	if (check[y][x] != -1) 
		return check[y][x];

	// 목적지라면 1 리턴
	if (x == n && y == m)
		return 1;
	
	// 방문 했기 때문에 0으로 초기화
	check[y][x] = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx <= 0 || nx > n) continue;
		if (ny <= 0 || ny > m) continue;
		if (map[y][x] <= map[ny][nx]) continue;
		
		// 4 방면에서 갈 수 있는 수 ++ 
		check[y][x] += dfs(nx, ny);
	}
	return check[y][x];
}
int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	memset(check, -1, sizeof(check));
	
	printf("%d", dfs(1, 1));
}