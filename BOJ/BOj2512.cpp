#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;
typedef long long ll;
int n;
ll total, t, maxV;
vector<ll> vt;
int main()
{
	scanf("%d", &n);
	vt.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &vt[i]);
		t += vt[i];
		maxV = max(maxV, vt[i]);
	}
	scanf("%lld", &total);

	ll left = 0, right = LLONG_MAX;
	if (t <= total) {
		right = maxV;
	}
	else {
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll tmp = 0;

			for (int i = 1; i <= n; ++i) {
				if (vt[i] <= mid)
					tmp += vt[i];
				else
					tmp += mid;
			}
			if (tmp > total) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	printf("%lld", right);
}