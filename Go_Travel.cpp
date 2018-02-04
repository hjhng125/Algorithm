#include<cstdio>
#include<vector>
using namespace std;

void init();
void unionSet(int, int);
int findSet(int);
int n, m;

vector<int> parent;
int main()
{
	int u, v;

	parent.resize(201);
	
	scanf("%d", &n);	
	scanf("%d", &m);
	init();
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &u);
			if (u)
				unionSet(i,j); // 1인 부분에 index union
		}
	}
	scanf("%d",&u);
	v = findSet(u); // 제일 처음에 들리는 곳 findset 
	bool chk = false; 
	for (int i = 1; i < m; i++){
		scanf("%d", &u);
		if (findSet(u) != v) // 처음에 들리는 곳에 갈 수 있는지 확인
			chk = true; // 못가는 경우 check
	}
	if (chk){ // 한군데라도 못가는 경우 NO
		printf("NO");
		return 0;
	}
	printf("YES");

	return 0;
}
void init()
{
	for (int i = 1; i <= n; i++){
		parent[i] = i;
	}
}
int findSet(int i)
{
	if (parent[i] == i){
		return i;
	}
	return parent[i] = findSet(parent[i]);
}
void unionSet(int u, int v)
{
	u = findSet(u);
	v = findSet(v);

	if (u == v)
		return;

	if (u > v)
		swap(u, v);
	parent[v] = u;
}