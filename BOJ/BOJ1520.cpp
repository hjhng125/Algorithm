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

	// -1�� 0���� ������ ���������ν� 
	// �̹� �����Ҵ� �������� ���̻� ��ΰ� ���� ������ ã�� �� �ְ�,
	// �湮���� ���� ������ ������ �����ϴ�.

	// �湮 �غôٸ� �� ���� ����� �� ����
	if (check[y][x] != -1) 
		return check[y][x];

	// ��������� 1 ����
	if (x == n && y == m)
		return 1;
	
	// �湮 �߱� ������ 0���� �ʱ�ȭ
	check[y][x] = 0;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx <= 0 || nx > n) continue;
		if (ny <= 0 || ny > m) continue;
		if (map[y][x] <= map[ny][nx]) continue;
		
		// 4 ��鿡�� �� �� �ִ� �� ++ 
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