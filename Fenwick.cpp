#include<cstdio>
#include<vector>

using namespace std;

void init(int, int);
int sum(int);
int n, m;
int input;
vector<int> arr;
vector<int> tree;
int main()
{
	scanf("%d %d", &n, &m);
	arr.resize(n + 1);
	tree.resize(n + 1);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &arr[i]);
		init(i, arr[i]);
	}
	int s, e;
	for (int i = 0; i < m; ++i){
		scanf("%d %d", &s, &e);
		printf("%d\n", sum(e) - sum(s - 1)); // 처음부터의 합을 구하는 경우가 아닐 경우 빼줘야한다.
	}

	return 0;
}
void init(int i, int diff)
{
	while (i < tree.size()){
		tree[i] += diff;
		i += (i & -i);
	}
}
int sum(int i)
{
	int result = 0;

	while (i > 0){
		result += tree[i];
		i -= (i & -i);
	}
	return result;
}