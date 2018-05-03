#include<cstdio>
#define MAX 10
using namespace std;

int n, m;
int cnt, min = 1e9;
int map[MAX][MAX];
int check[MAX];
bool flag;
void Clear(){
	for (int i = 0; i < n; ++i)
		check[i] = 0;
}
bool isAvail()
{
	for (int i = 0; i < n; ++i){
		if (check[i] == 0)
			return false;
	}
	return true;
}
void dfs(int v)
{
	cnt++;
	for (int i = 0; i < n; ++i){
		if (map[v][i] == 1)
			check[i]++;
	}
	if (!isAvail()){
		for (int i = v + 1; i < m; ++i)
			dfs(i);
	}
	else{
		flag = true;
		if (min > cnt)
			min = cnt;
	}
	cnt--;
	for (int i = 0; i < n; ++i){
		if (map[v][i] == 1)
			check[i]--;
	}
}
int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i){
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; ++j){
			int avail;
			scanf("%d", &avail);
			map[i][avail-1] = 1;
		}
	}
	flag = false;
	for (int i = 0; i < m; i++){
		dfs(i);
		Clear();
	}

	if (flag) printf("%d", min);
	else printf("-1");

	return 0;
}
