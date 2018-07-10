#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int t;
int n, m;
vector<int> tree, arr;
int update(int tree_idx, int value, int idx, int start, int end) {
	if (idx > end || idx < start) return tree[tree_idx];
	if (start == end) return tree[tree_idx] = value;

	int mid = (start + end) / 2;
	
	return tree[tree_idx] = update(tree_idx * 2, value, idx, start, mid) + update(tree_idx * 2 + 1, value, idx, mid + 1, end);
}

int change(int tree_idx, int left, int right, int start, int end) {
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return tree[tree_idx];

	int mid = (start + end) / 2;
	return tree[tree_idx] = change(tree_idx * 2, left, right, start, mid) + change(tree_idx * 2 + 1, left, right, mid + 1, end);
}

int main()
{
	scanf("%d", &t);
	
	while (t > 0) {
		scanf("%d %d", &n, &m);

		int h = (int)ceil(log2(n + m));
		int size = pow(2, h + 1) - 1;
		
		arr.clear();
		tree.clear();
		arr.resize(n + 1, 0);
		tree.resize(size + 1, 0);
		
		int idx = m + 1;
		for (int i = idx; i <= n + m; ++i) {
			update(1, 1, i, 1, n + m);
			arr[i - m] = i;
		}

		idx = m;
		for (int i = 1; i <= m; ++i) {
			int dvd;
			scanf("%d", &dvd);
			printf("%d ", change(1, 1, arr[dvd] - 1, 1, n + m));
		
			update(1, 0, arr[dvd], 1, n + m);
			arr[dvd] = idx--;
			update(1, 1, arr[dvd], 1, n + m);
		}
		printf("\n");
		t--;
	}
	return 0;
}