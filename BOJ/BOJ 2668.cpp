#include<cstdio>
#include<algorithm>

using namespace std;

int n, cnt;
int arr[101];
bool visit[101], list[101], chk;

void dfs(int i, int j) {
	visit[i] = true;
	if (arr[i] == j)
		chk = true;
	if (!visit[arr[i]]) 
		dfs(arr[i], j);
}
int main()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; ++i) {
		fill(visit + 1, visit + n + 1, false);
		chk = false;
		dfs(i, i);
		if (chk) {
			list[i] = true;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; ++i)
		if(list[i])
			printf("%d\n", i);
	
	return 0;
}