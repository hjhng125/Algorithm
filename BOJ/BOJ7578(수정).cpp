#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>

#define MAX 1000001
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int n;
vector<pi> matching;
vector<int> tree, arr;
int sum(ll idx, int left, int right, int start, int end ) {

	if (end < left || start > right) return 0;
	if (start <= left && right <= end) return tree[idx];
	int mid = (left + right) / 2;

	return tree[idx] = sum(idx * 2, left, mid,start,end) + sum(idx * 2 + 1, mid + 1, right, start, end);
}
void update(ll idx, int left, int right, int pos) {
	if (pos < left || pos > right) return;
	if (left == right) {
		tree[idx] = 1;
		return;
	}
	int	mid = (left + right) / 2;
	
	update(idx * 2, left, mid, pos);
	update(idx * 2 + 1, mid + 1, right, pos);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int main()
{
	scanf("%d", &n);
	arr.resize(MAX);
	matching.resize(n + 1);
	int h = (int)ceil(log2(n));
	ll tree_size = pow(2, h + 1) - 1;
	tree.resize(tree_size + 1);
	
	int pos;
	for (int i = 1; i <= n; ++i) {	
		scanf("%d", &pos);
		arr[pos] = i;
	}
	for (int i = 1; i <= n; ++i) {	
		scanf("%d", &pos);
		matching[i] = make_pair(i, arr[pos]);
	}
	ll total = 0;
	sort(matching.begin() + 1, matching.end());
	// 루프를 돌며 해당 Edge가 교차하는 것이 있는지
	// 확인하며 update 함수를 통해 Vertex를 매칭함
	for (int i = 1; i <= n; ++i) {
		total += sum(1,1,n,matching[i].second, n);
		update(1, 1, n, matching[i].second);
	}
	printf("%lld", total);
	return 0;
}