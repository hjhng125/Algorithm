#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;
int n, m;
ll card[500001], input[500001];
int output[500001];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &card[i]);
	}
	sort(card + 1, card + n + 1);

	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%lld", &input[i]);
		output[i] = upper_bound(card + 1, card + n + 1, input[i]) - lower_bound(card + 1, card + n + 1, input[i]);
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d ", output[i]);
	}
}