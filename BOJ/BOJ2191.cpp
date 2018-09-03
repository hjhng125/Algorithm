#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int n, m, s, v;
vector<pair<double, double> > mouse, cave;
vector<vector<int> > vt;
vector<int> visit, B;
double x, y;

bool dfs(int cur) {
	if (visit[cur]) return false;
	visit[cur] = true;

	for (int next : vt[cur]) {
		if (!B[next] || dfs(B[next])) {
			B[next] = cur;
			return true;
		}
	}
	return false;
}

int bmatch() {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		fill(visit.begin(), visit.end(), 0);
		if (dfs(i)) cnt++;
	}
	return cnt;
}
int main()
{
	scanf("%d %d %d %d", &n, &m, &s, &v);
	mouse.resize(n + 1);
	cave.resize(n + m + 1);
	vt.resize(n + 1);
	B.resize(n + m + 1);
	visit.resize(n + m + 1);
	
	for (int i = 1; i <= n; ++i) {
		scanf("%lf %lf", &x, &y);
		mouse[i] = { x,y };
	}

	for (int i = n + 1; i <= n + m; ++i) {
		scanf("%lf %lf", &x, &y);
		cave[i] = { x,y };
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = n + 1; j <= n + m; ++j) {
			double dist = sqrt(pow(cave[j].first - mouse[i].first, 2) + pow(cave[j].second - mouse[i].second, 2));
			if ((double)s*v >= dist)
				vt[i].push_back(j);
		}
	}
	printf("%d", n - bmatch());
}