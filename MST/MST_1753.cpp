#include<cstdio>
#include<queue>
#include<vector>
#include<utility>

using namespace std;
#define INF 1e9
typedef pair<int, int> pi;

bool check(int);
void init(int);
void prim(int);

struct comp{
	bool operator()(pi p1, pi p2){
		return p1.second > p2.second;
	}
};
vector<vector<pi> > adj;
priority_queue<pi, vector<pi>, comp> pq;
vector<bool> bool_v;
int nv, ne;
int total = 0;

int main()
{
	scanf("%d %d", &nv, &ne);
	
	init(nv);
	prim(1);

	printf("%d", total);
	return 0;
}
bool check(int v)
{
	if (!bool_v[v-1])
		return false;
	return true;
}
void init(int nv)
{
	int u, v, w;

	adj.resize(nv + 1);
	for (int i = 1; i <= ne; ++i){
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	for (int i = 1; i <= nv; ++i){
		bool_v.push_back(true);
		pq.push(make_pair(i, INF));
	}
}
void prim(int s)
{
	pq.push(make_pair(s, 0));

	while (!pq.empty()){
		pi u = pq.top();
		pq.pop();

		for (int i = 0; i < adj[u.first].size(); ++i){
			pi here = adj[u.first][i];
			if (check(here.first)){
				pq.push(make_pair(here.first, here.second));
			}
		}
		if (check(u.first)){
			total += u.second;
			bool_v[u.first - 1] = false;
		}
	}
}
