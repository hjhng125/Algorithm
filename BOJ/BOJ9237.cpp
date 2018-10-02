#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int n, day = 1;
vector<int> tree;

int main()
{
	scanf("%d", &n);
	tree.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &tree[i]);
	}
	sort(tree.begin() + 1, tree.end(), greater<int>());
	
	int d = day;
	for (int i = 1; i <= n; ++i) {
		day++;
		d = max(d, tree[i] + day);
	}
	printf("%d", d);
}