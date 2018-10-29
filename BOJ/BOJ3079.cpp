#include<cstdio>
#include<vector>

using namespace std;
typedef long long ll;
ll n, m;
vector<ll> t;

int main()
{
	scanf("%d %d", &n, &m);
	t.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &t[i]);
	}

	ll left = 1, right = 987654321987654LL;
	ll ans = 0;
	
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll num = 0;
		for (int i = 0; i < n; ++i) {
			num += mid / t[i];	
		}
		if (num >= m) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1; 
		}
	}
	printf("%lld", ans);
}