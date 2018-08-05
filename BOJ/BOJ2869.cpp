#include<cstdio>
#include<vector>

using namespace std;

long a, b, v;

int main()
{
	scanf("%d %d %d", &a, &b, &v);
	
	long left = 1;
	long right = v;

	long cur = 0;
	long ans = 0;
	while (left <= right) {
		long mid = (left + right) / 2;
		cur = mid * (a - b) + a;
		if (cur >= v) {
			ans = mid + 1;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d", right);
}