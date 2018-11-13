#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int tc, l;
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
bool visit[501][501];

int main() 
{
	scanf("%d", &tc);
	while (tc--) {
		memset(visit, false, sizeof(visit));
		scanf("%d", &l);
		int sX, sY, dX, dY;
		scanf("%d %d", &sX, &sY);
		scanf("%d %d", &dX, &dY);

		queue<pair<int, int> > q;
		q.push(make_pair(sX, sY));
		int cnt = 0;
		bool flag = false;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (x == dX && y == dY) {
					printf("%d\n", cnt);
					flag = true;
					break;
				}
				for (int i = 0; i < 8; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
					if (visit[ny][nx]) continue;

					q.push(make_pair(nx, ny));
					visit[ny][nx] = true;
				}
			}
			if (flag)
				break;
			cnt++;
		}
	}
}