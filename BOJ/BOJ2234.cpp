#include<cstdio>
#include<algorithm>
using namespace std;

int map[51][51], visit[51][51], room_info[51 * 51];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int n, m;
int room_num, room_size;
int max_room;

void dfs(int curY, int curX) {
	visit[curY][curX] = room_num;
	room_info[room_num]++;
	room_size++;
	
	for (int i = 0; i < 4; ++i) {
		int nx = curX + dx[i];
		int ny = curY + dy[i];
		
		if (nx <= 0 || nx > n) continue;
		if (ny <= 0 || ny > m) continue;
		if (map[ny][nx] & 1 << i) continue;
		if (visit[ny][nx]) continue;
		dfs(ny, nx);
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!visit[i][j]) {
				room_num++;
				room_size = 0;
				dfs(i ,j);
				max_room = max(max_room, room_size);
			}
		}
	}
	int merge_room = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k < 4; ++k) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (nx <= 0 || nx > n) continue;
				if (ny <= 0 || ny > m) continue;
				if (visit[i][j] != visit[ny][nx])
					merge_room = max(merge_room, room_info[visit[i][j]] + room_info[visit[ny][nx]]);
			}
		}
	}
	printf("%d\n", room_num);
	printf("%d\n", max_room);
	printf("%d\n", merge_room);
}