#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int map[26][26];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool visit[26][26];
vector<int> organization;
queue<pair<int, int> > q;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%1d",&map[i][j]);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] || !map[i][j])
				continue;
			visit[i][j] = true;
			q.push(make_pair(j, i));
			int cnt = 1;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
					if (visit[ny][nx]) continue;
					if (!map[ny][nx]) continue;
					q.push(make_pair(nx, ny));
					visit[ny][nx] = true;
					cnt++;
				}
			}
			organization.push_back(cnt);
		}
	}
	sort(organization.begin(), organization.end());
	printf("%d\n", organization.size());
	for (int i = 0; i < organization.size(); ++i) {
		printf("%d\n", organization[i]);
	}
}