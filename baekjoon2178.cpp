#include<cstdio>
#include<queue>

#define MAX 101

using namespace std;
typedef pair<int, int> pii;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, m;
int table[MAX][MAX];
int visited[MAX][MAX];
queue<pii> q;

int BFS(int x, int y){
	q.push(make_pair(x, y));
	visited[1][1] = 1; // 처음 시작점의 코스트 : 1
	while (!q.empty()){
		pii here = q.front();
		q.pop();
		if (here.second == m && here.first == n) break;
		for (int k = 0; k < 4; k++){
			int next_x = here.first + dx[k];
			int next_y = here.second + dy[k];
			if ((next_x >= 1 && next_y >= 1) && (next_x <= m && next_y <= n)){
				if (!visited[next_y][next_x]){ // 방문하지 않은곳
					if (table[next_y][next_x]){
						q.push(make_pair(next_x, next_y));
						visited[next_y][next_x] = visited[here.second][here.first] + 1; // 현재 경로에 전의 경로 +1
					}
				}
			}
		}
	}
	return visited[n][m];
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			scanf("%1d", &table[i][j]);
			visited[i][j] = 0;
		}
	}
	printf("%d",BFS(1, 1));

	return 0;
}