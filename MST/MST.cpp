#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct E{ // 간선의 정보
	int from;
	int to;
	int cost;
};
struct  comp{ 
	bool operator()(E d1, E d2){
		return d1.cost > d2.cost;
	}
};
void init(int);
int findSet(int);
void unionSet(int, int);

priority_queue<E, vector<E>, comp> pq; // cost값으로 오름차순
int nv, ne, total = 0;
int parent[10001];

int main(void)
{
	E e;
	scanf("%d %d", &nv, &ne);

	for (int i = 1; i <= ne; i++){

		scanf("%d %d %d", &e.from, &e.to, &e.cost);
		pq.push(e);
	}
	init(nv);

	while(!pq.empty()){
		unionSet(pq.top().from, pq.top().to); 
		pq.pop();
	}
	printf("%d",total);
	return 0;
}
void init(int nv)
{
	for (int i = 1; i <= nv; i++) // 처음에 vertex의 parent를 자기 자신으로 초기화
		parent[i] = i;
}
int findSet(int u)
{
	if (parent[u] == u) // parent가 자기 자신이면 그대로 return
		return u;
	else
		return parent[u] = findSet(parent[u]); // parent가 따로 있다면 그것을 재귀로 찾는다.
}
void unionSet(int u, int v)
{
	// parent를 찾는다.
	u = findSet(u); 
	v = findSet(v);

	// 같은 parent를 갖는 다는 것은 cycle이라는 것
	if (u == v)
		return;

	// 무분별하게 tree를 만들지 않고 작은 수를 root로 두기 위해서
	else if (v > u)
		swap(v, u);	

	// u의 parent를 v로 
	parent[u] = v;
	total += pq.top().cost;
}