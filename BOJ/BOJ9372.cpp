#include<cstdio>
#include<vector>
using namespace std;
int n, m;
typedef struct Edge{
	int from;
	int to;
}edge;
vector<edge> e;
vector<int> parent;
int find_set(int i) {
	if (parent[i] == i)
		return i;
	return parent[i] = find_set(parent[i]);
}
bool union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);

	if (a == b) return false;

	parent[a] = b;
	return true;
}
int main()
{
	int t;
	
	scanf("%d", &t);
	while (t > 0) {
		scanf("%d %d", &n, &m);
		e.resize(m + 1);
		parent.resize(n + 1);
		for (int i = 1; i <= m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			e[i].from = a;
			e[i].to = b;
		}
		for (int i = 1; i <= n; ++i) {
			parent[i] = i;
		}
		int cnt = 0;
		for (int i = 1; i <= m; ++i) {
			if (union_set(e[i].from, e[i].to))
				cnt++;
		}
		printf("%d\n",cnt);
		t--;
	}
	return 0;
}