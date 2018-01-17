#include<cstdio>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

void topology();

vector<int> ind;
vector<vector<int> > adj;

int main(void)
{
	int num, edge;
	int u, v;

	scanf("%d %d", &num, &edge);
	
	adj.resize(num + 1);
	ind.resize(num + 1);

	for (int i = 0; i < edge; i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		ind[v]++;
	}
	topology();
	
	return 0;
}
void topology()
{
	priority_queue<int, vector<int>, greater<int> > pq;
	
	for (int i = 1; i < ind.size(); i++){
		if (!ind[i])
			pq.push(i);
	}
	while (!pq.empty()){
		int tmp = pq.top();
		printf("%d ",tmp);
		pq.pop();

		for (int i = 0; i < adj[tmp].size(); i++){
			ind[adj[tmp][i] ]--;
			
			if (!ind[adj[tmp][i]])
				pq.push(adj[tmp][i]);
		}
	}
}