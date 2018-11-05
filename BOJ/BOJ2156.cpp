#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int arr[10001];
int dp[10001];
int tc;

int main()
{

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", arr + i);

	for (int i = 1; i <= n; ++i) {
		if (i == 1)
			dp[i] = arr[i];
		else {
			dp[i] = arr[i] + arr[i - 1];
		}
	}
	for (int i = 3; i <= n; ++i) {
		int result = 0;
		result = max(arr[i] + dp[i - 2], dp[i - 1]); // 내가 현재의 포도주를 먹지 않았을 경우, 현재의 포도주를 마시고 이전꺼를 안마실 경우
		result = max(result, arr[i] + arr[i - 1] + dp[i - 3]); // 위의 최대값과 현재의 포도주와 이전의 포도주를 마신 경우의 최대값을 구한다.
		dp[i] = result;
	}
	printf("%d\n", dp[n]);

}