#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
typedef struct {
	int wi, he, kn, cnt;
}v;
int visit[201][201][31];
int matrix[201][201];
int horseX[8] = { -2,-1,1,2,-2,-1,1,2 };
int horseY[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int k, w, h;
int main()
{
	scanf("%d", &k);
	scanf("%d %d", &w, &h);

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			scanf("%d", &matrix[i][j]);
		}
	}

	queue<v> q;
	q.push({ 1,1,k,0 });
	visit[1][1][k] = 1;
	int x, y, ck, ccnt;
	while (!q.empty()) {
		int size = q.size();
		for (int idx = 0; idx < size; ++idx) {
			x = q.front().wi;
			y = q.front().he;
			ck = q.front().kn;
			ccnt = q.front().cnt;
			q.pop();
			if (x == w && y == h) {
				printf("%d\n", ccnt);
				return 0;
			}
			int nextX, nextY;
			for (int i = 0; i < 4; ++i) {
				nextX = x + dx[i];
				nextY = y + dy[i];
				if ((nextX <= 0 || nextX > w) || (nextY <= 0 || nextY > h))
					continue;
				if (matrix[nextY][nextX])
					continue;
				if (visit[nextY][nextX][ck])
					continue;
				q.push({ nextX, nextY,ck ,ccnt + 1 });
				visit[nextY][nextX][ck] = 1;
			}
			if (ck > 0) {
				for (int i = 0; i < 8; ++i) {
					nextX = x + horseX[i];
					nextY = y + horseY[i];
					if ((nextX <= 0 || nextX > w) || (nextY <= 0 || nextY > h))
						continue;
					if (matrix[nextY][nextX])
						continue;
					if (visit[nextY][nextX][ck - 1])
						continue;
					q.push({ nextX, nextY, ck - 1, ccnt + 1 });
					visit[nextY][nextX][ck - 1] = 1;
				}
			}

		}

	}
	printf("-1\n");
}
