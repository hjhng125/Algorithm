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
		result = max(arr[i] + dp[i - 2], dp[i - 1]); // ���� ������ �����ָ� ���� �ʾ��� ���, ������ �����ָ� ���ð� �������� �ȸ��� ���
		result = max(result, arr[i] + arr[i - 1] + dp[i - 3]); // ���� �ִ밪�� ������ �����ֿ� ������ �����ָ� ���� ����� �ִ밪�� ���Ѵ�.
		dp[i] = result;
	}
	printf("%d\n", dp[n]);

}