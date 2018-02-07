#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct E{ // ������ ����
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

priority_queue<E, vector<E>, comp> pq; // cost������ ��������
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
	for (int i = 1; i <= nv; i++) // ó���� vertex�� parent�� �ڱ� �ڽ����� �ʱ�ȭ
		parent[i] = i;
}
int findSet(int u)
{
	if (parent[u] == u) // parent�� �ڱ� �ڽ��̸� �״�� return
		return u;
	else
		return parent[u] = findSet(parent[u]); // parent�� ���� �ִٸ� �װ��� ��ͷ� ã�´�.
}
void unionSet(int u, int v)
{
	// parent�� ã�´�.
	u = findSet(u); 
	v = findSet(v);

	// ���� parent�� ���� �ٴ� ���� cycle�̶�� ��
	if (u == v)
		return;

	// ���к��ϰ� tree�� ������ �ʰ� ���� ���� root�� �α� ���ؼ�
	else if (v > u)
		swap(v, u);	

	// u�� parent�� v�� 
	parent[u] = v;
	total += pq.top().cost;
}