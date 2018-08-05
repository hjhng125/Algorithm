#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n, k;
int arr[501] = { 0, };
double sd(int k, double midAns)
{
	for (int i = 1; i <= n - k + 1; ++i) {
		double v = 0.0;
		long long total = 0.0;
		for (int j = i; j < k + i; ++j) {
			total += arr[j];
		}
		double m = (double)total / k;
		for (int j = i; j < k + i; ++j) {
			v += (double)(arr[j] - m)*(double)(arr[j] - m);
		}
		midAns = min(midAns, v/k);
	}
	return midAns;
}
int main()
{
	scanf("%d %d", &n, &k);
	
	for (int i = 1; i <= n; ++i) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}		
 
	
	double ans = 9007199254740992.0;
	for (int i = k; i <= n; ++i) {
		ans = min(ans, sd(i, ans));
	}
	printf("%.12f\n", sqrt(ans));

	return 0;
}