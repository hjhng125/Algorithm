#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
vector<pair<int, int> > arr;
vector<int> val;
int main()
{
	scanf("%d", &n);
	arr.resize(n + 1);
	val.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		val[i] = arr[i].second;
	}
	
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (i - j >= arr[j].first) {
				val[i] = max(arr[i].second + val[j], val[i]);
			}
		}
	}
	int max_value = 0;
	for (int i = 1; i <= n; ++i) {
		if (i + arr[i].first - 1 <= n)
			max_value = max(max_value, val[i]);
	}
	printf("%d", max_value);
}