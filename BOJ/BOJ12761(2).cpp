#include<cstdio>
#include<queue>
using namespace std;

int a, b, n, m;
queue<int> q;
bool visit[100001];
int main() {

	scanf("%d %d %d %d", &a, &b, &n, &m);
	
	q.push(n);
	visit[n] = true;
	int cnt = 0;
	while (!q.empty()) {
		int move[8] = { -1,1,-a,a,b,-b,a,b };
		int size = q.size();

		for (int j = 0; j < size; ++j) {
			int cur = q.front();
			q.pop();
			if (cur == m) {
				printf("%d",cnt);
				return 0;
			}
			for (int i = 0; i < 8; i++) {
				int next;
				if (i < 6) 	next = cur + move[i];
				else next = cur * move[i];
				if (next < 0 || next > 100000) continue;
				if (visit[next]) continue;
				q.push(next);
				visit[next] = true;
			}
		}
		cnt++;
	}
}