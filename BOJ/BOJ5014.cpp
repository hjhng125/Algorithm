#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;

int f, s, g, u, d;
vector<int> visit, moving;
queue<int> q;
int main()
{
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	visit.resize(f + 1);
	q.push(s);
	moving.push_back(u);
	moving.push_back(-d);
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int k = 0; k < size; ++k) {
			int cur = q.front();
			q.pop();
			if (cur == g) {
				printf("%d", cnt);
				exit(0);
			}
			for (int i = 0; i < 2; ++i) {
				int next = cur + moving[i];
				if (next > f || next <= 0) continue;
				if (visit[next]) continue;
				q.push(next);
				visit[next] = 1;
			}
		}
		cnt++;
	}
	printf("use the stairs");
}