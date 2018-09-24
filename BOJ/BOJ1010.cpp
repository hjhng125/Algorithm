/*
#include<cstdio>

using namespace std;

int t;
int n, m;

int main()
{
	scanf("%d", &t);

	while (t--) {
		long long total = 1;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; ++i) {
			total = total * (m - i + 1) / i;
		}
		printf("%d\n", total);
	}
}
*/
#include<cstdio>
#include<cstring>

using namespace std;

int n, m;
int dp[31][31];
int main()
{
	int t;
	
	scanf("%d", &t);
	while (t--) {
		
		scanf("%d %d", &n, &m);

		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= m; ++j) {
				if(i != 1){
					for (int k = j - 1; k > 0; --k) {
						dp[i][j] += dp[i - 1][k];
					}
				}
				else dp[i][j] = j;
			}
		}
		printf("%d\n", dp[n][m]);
	}
}

