#include<cstdio>
#include<queue>
using namespace std;

int a, b, n, m;
int cnt;
queue<int> q;
bool visit[100001];

int main()
{
	scanf("%d %d %d %d", &a, &b, &n, &m);
	
	q.push(n);
	visit[n] = 1;
	while (!q.empty()) {
		cnt++;
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			int cur = q.front();
			q.pop();
			if (cur == m) {
				printf("%d", cnt-1);
				return 0;
			}
			if (cur - 1 >= 0 && !visit[cur - 1]) {
				q.push(cur - 1);
				visit[cur - 1] = true;
			}
			if (cur + 1 <= 100000 && !visit[cur + 1]) {
				q.push(cur + 1);
				visit[cur + 1] = true;
			}
			if (cur - a >= 0 && !visit[cur - a]) {
				q.push(cur - a);
				visit[cur - a] = true;
			}
			if (cur + a <= 100000 && !visit[cur + a]) {
				q.push(cur + a);
				visit[cur + a] = true;
			}
			if (cur - b >= 0 && !visit[cur - b]) {
				q.push(cur - b);
				visit[cur - b] = true;
			}
			if (cur + b <= 100000 && !visit[cur + b]) {
				q.push(cur + b);
				visit[cur + b] = true;
			}
			if (cur * a <= 100000 && !visit[cur * a]) {
				q.push(cur * a);
				visit[cur * a] = true;
			}
			if (cur * b <= 100000 && !visit[cur * b]) {
				q.push(cur * b);
				visit[cur * b] = true;
			}
		}
	}
	return 0;
}