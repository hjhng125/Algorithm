#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int n, m;
int parent[100001];
typedef struct Edge {
	int a, b, c;
}E;
vector<E> set;
bool comp(E e1, E e2) {
	return e1.c < e2.c;
}

int find_set(int i) {
	if (parent[i] == i)
		return i;
	else
		return parent[i] = find_set(parent[i]);
}

bool union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a == b) 
		return false;

	parent[a] = b;
	return true;
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	set.resize(m + 1);

	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		set[i].a = a; set[i].b = b; set[i].c = c;
		parent[i] = i;
	}
	sort(set.begin(), set.end(), comp);
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		if (union_set(set[i].a, set[i].b))
			ans += set[i].c;
	}
	printf("%d",ans);
	return 0;
}