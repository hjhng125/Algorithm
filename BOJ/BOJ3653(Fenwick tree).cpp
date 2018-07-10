#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int t;
int n, m;
vector<int> tree, arr;
void update(int i, int value) {
	while (i < tree.size()) {
		tree[i] += value;
		i += (i & -i);
	}
}

int print(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main()
{
	scanf("%d", &t);

	while (t > 0) {
		scanf("%d %d", &n, &m);

		arr.clear();
		tree.clear();
		arr.resize(n + 1, 0);
		tree.resize(n + m + 1, 0);

		int idx = m + 1;
		for (int i = idx; i <= n + m; ++i) {
			update(i, 1);
			arr[i - m] = i;
		}
		idx = m;
		for (int i = 1; i <= m; ++i) {
			int dvd;
			scanf("%d", &dvd);
			printf("%d ", print(arr[dvd] - 1));

			update(arr[dvd], -1);
			arr[dvd] = idx--;
			update(arr[dvd], 1);
		}
		printf("\n");
		t--;
	}
	return 0;
}
