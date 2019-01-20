#include<cstdio>
#include<algorithm>
using namespace std;
int r, c;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char board[21][21];
int set[26];
int dfs(int y, int x, int cnt) {
	set[board[y][x] - 'A'] = 1;
	int length = cnt;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c || set[board[ny][nx] - 'A']) continue;
		length = max(length, dfs(ny, nx, cnt + 1));
		set[board[ny][nx] - 'A'] = 0;
	}
	return length;
}
int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i)  
		scanf("%s", board[i]);
	printf("%d", dfs(0, 0, 1));
}