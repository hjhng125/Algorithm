#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	int n, k;
	int second = -1;
	int visit[100001] = { 0, };
	queue<int> q;

	scanf("%d %d", &n, &k);
	q.push(n);
	visit[n] = 1;
	while (!q.empty()){
		second++;
		if (n == k)
			break;
		int q_size = q.size();
		for (int i = 0; i<q_size; ++i){
			int cur = q.front();
			q.pop();
			if (cur == k){
				printf("%d", second);
				return 0;
			}
			if (cur - 1 >= 0 && !visit[cur - 1]){ 
				q.push(cur - 1); 
				visit[cur - 1] = 1;
			}
			if (cur + 1 <= 100001 && !visit[cur + 1]){
				q.push(cur + 1);
				visit[cur + 1] = 1;
			}
			if (cur * 2 <= 100001 && !visit[cur * 2]){
				q.push(cur * 2);
				visit[cur * 2] = 1;
			}
		}
	}
	printf("%d",second);

	return 0;
}