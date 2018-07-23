#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 101
using namespace std;
typedef pair<int, int> pi;
int n, m, k;
int arr[MAX][MAX], visit[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> s;
queue<pi> q;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
		for (int i = y1+1; i <= y2; ++i) {
			for (int j = x1+1; j <= x2; ++j) {
				if (!arr[i][j])
					arr[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!arr[i][j] && !visit[i][j]) {
				q.push({ i,j });
				visit[i][j] = 1;
				int size = 1;
				while (!q.empty()) {
					pi here = q.front();
					q.pop();
					for (int idx = 0; idx < 4; ++idx) {
						int nextx = here.second + dx[idx];
						int nexty = here.first + dy[idx];
						if ((nextx < 1 || nextx > m) || (nexty < 1 || nexty > n)) continue;
						if (!visit[nexty][nextx] && !arr[nexty][nextx]) {
							q.push({ nexty,nextx });
							visit[nexty][nextx] = 1;
							size++;
						}
					}
				}
				s.push_back(size);
			}
		}
	}
	sort(s.begin(), s.end());
	printf("%d\n",s.size());
	for (int i = 0; i < s.size(); ++i) {
		printf("%d ", s[i]);
	}
	return 0;
}