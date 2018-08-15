#include<cstdio>
using namespace std;

int n;
int dp[21];
int main()
{
	int cost = 0;
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &a, &b);

		if (dp[i] > dp[i + 1])
			dp[i + 1] = dp[i];

		if (dp[i + a] < dp[i] + b)
			dp[i + a] = dp[i] + b;
	}
	printf("%d", dp[n + 1]);
}