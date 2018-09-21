#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int card[1001], dp[1001];
int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", card + i);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	printf("%d", dp[n]);
	return 0;
}