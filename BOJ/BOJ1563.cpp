#include<cstdio>
#include<cstring>
using namespace std;

int dp[1001][2][3];
int n;
int mod = 1000000;

int solution(int cur, int l, int a) {
	if (l == 2)
		return 0;
	if (a == 3)
		return 0;
	if (cur == n)
		return 1;

	int ans = dp[cur][l][a];
	
	if (ans != -1) return ans;
	
	ans = 0;
	ans += solution(cur + 1, l, 0);
	ans += solution(cur + 1, l + 1, 0);
	ans += solution(cur + 1, l, a + 1);

	return ans;
}
int main()
{
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d", solution(0,0,0) % mod);
}