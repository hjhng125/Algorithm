#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, cnt, max_cnt = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<vector<int> > dnm;
vector<vector<int> > visit;
//dfs를 이용하여 갈 수 있는 곳 체크
int dfs(int curX, int curY) {
	//visit 어레이를 이용하여 방문했는지 아닌지와 함께 각 최대 일수를 구할 수 있다.
	if (!visit[curY][curX]) {
		visit[curY][curX]++;
		for (int i = 0; i < 4; ++i) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX < 1 || nextX > n) continue;
			if (nextY < 1 || nextY > n) continue;
			if (dnm[nextY][nextX] > dnm[curY][curX]) {
				//recursive를 빠져나오며 점점 카운트를 올려 최대 일 수를 알 수 있다.
				visit[curY][curX] = max(visit[curY][curX], dfs(nextX, nextY) + 1);
			}
		}
	}
	return visit[curY][curX];
}
int main()
{
	scanf("%d", &n);
	
	dnm.resize(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &dnm[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			visit.resize(n + 1, vector<int>(n + 1, 0));
			max_cnt = max(max_cnt, dfs(j, i));
		}
	}
	printf("%d", max_cnt);
}