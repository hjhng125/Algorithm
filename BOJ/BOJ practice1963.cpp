#include<cstdio>
#include<queue>
using namespace std;

int tc;
int num1, num2;
int divi[4];
bool visit[10000], primes[10000];
int main()
{
	scanf("%d", &tc);
	for (int i = 2; i <= 100; ++i) {
		if (primes[i])continue;
		for (int j = i * i; j <= 10000; j += i) {
			primes[j] = true;
		}
	}

	for (int i = 0; i < tc; ++i) {
		fill(visit + 1000, visit + 10000, 0);
		scanf("%d %d", &num1, &num2);

		queue<pair<int, int> > q;
		q.push({ num1, 0 });
		visit[num1] = true;
		int cnt;
		while (!q.empty()) {
			int here = q.front().first;
			cnt = q.front().second;
			q.pop();
			
			if (here == num2) break; 

			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 10; ++j) {
					divi[0] = here / 1000;
					divi[1] = here % 1000 / 100;
					divi[2] = here % 1000 % 100 / 10;
					divi[3] = here % 10;

					if (i == 0 && j == 0)
						continue;
					divi[i] = j;
					int next = divi[0] * 1000 + divi[1] * 100 + divi[2] * 10 + divi[3];
					if (visit[next]) continue;
					if (primes[next]) continue;
					visit[next] = true;
					q.push({ next, cnt + 1 });
				}
			}
		}
		if (!visit[num2]) printf("Impossible\n");
		else printf("%d\n", cnt);
	}
}