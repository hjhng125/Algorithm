#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
int n, m;
int inputNum[100001];
vector<int> tree;
int minimum;
vector<int> minV;
int init(int idx, int left, int right) {
	if (left == right) return tree[idx] = inputNum[left];
	int mid = (left + right) / 2;
	return tree[idx] = min(init(idx * 2, left, mid), init(idx * 2 + 1, mid + 1, right));
}
int check(int idx, int left, int right, int start, int end) {
	if (left >= start && right <= end) return tree[idx];
	if (right < start || left > end) return 1e9 + 1;
	int mid = (left + right) / 2;

	return minimum = min(check(idx * 2, left, mid, start, end), check(idx * 2 + 1, mid + 1, right, start, end));	
}
int main()
{
	scanf("%d %d", &n, &m);
	int h = (int)ceil(log2(n));
	int size = pow(2, (h + 1)) - 1;
	tree.resize(size + 1);
	minV.resize(m + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inputNum + i);
	}
	init(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		int start, end;
		scanf("%d %d", &start, &end);
		minV[i] = check(1, 1, n, start, end);
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d\n",minV[i]);
	}
	
	return 0;
}