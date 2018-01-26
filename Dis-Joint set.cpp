#include<cstdio>
#include<vector>
using namespace std;

int findset(int);
void checking(int, int);
int parent[1000001];
int main(void)
{
	int n, m;
	int u, v;
	int flag;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i){
		scanf("%d %d %d", &flag, &u, &v);

		if (!flag)
			checking(u, v);
		else{
			if (findset(u) == findset(v))
				printf("yes\n");
			else
				printf("no\n");
		}
	}
}
int findset(int num)
{
	if (parent[num] == num)
		return num;
	else
		return parent[num] = findset(parent[num]);
}
void checking(int u, int v)
{
	u = findset(u);
	v = findset(v);

	if (u != v) parent[u] = v;
}