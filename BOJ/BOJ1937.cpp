#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, cnt, max_cnt = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<vector<int> > dnm;
vector<vector<int> > visit;
//dfs�� �̿��Ͽ� �� �� �ִ� �� üũ
int dfs(int curX, int curY) {
	//visit ��̸� �̿��Ͽ� �湮�ߴ��� �ƴ����� �Բ� �� �ִ� �ϼ��� ���� �� �ִ�.
	if (!visit[curY][curX]) {
		visit[curY][curX]++;
		for (int i = 0; i < 4; ++i) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX < 1 || nextX > n) continue;
			if (nextY < 1 || nextY > n) continue;
			if (dnm[nextY][nextX] > dnm[curY][curX]) {
				//recursive�� ���������� ���� ī��Ʈ�� �÷� �ִ� �� ���� �� �� �ִ�.
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