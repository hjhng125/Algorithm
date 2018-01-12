#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

void Topology(int);
void Indegree();
void Print();

vector<vector<int> > graph;
vector<int> visited;
vector<int> in;
stack<int> st;
queue<int> q;

int main(void)
{
	int n, m;
	int v, u;

	do{
		scanf("%d %d", &n, &m);
	} while ((n > 32000 && n < 1) || (m < 1 && m > 100000));

	graph.resize(n + 1);
	visited.resize(n + 1, 0);
	in.resize(n + 1, 0);

	for (int i = 0; i < m; ++i){
		scanf("%d %d", &v, &u);
		graph[v].push_back(u);
		in[u]++;
	}
	for (int i = 1; i <= n; ++i){
		if (!visited[i] && !graph[i].empty())
			Topology(i);
	}
	Print();
	Indegree();
}
void Topology(int start)
{
	visited[start] = 1;

	for (int i = 0; i < graph[start].size(); ++i){
		int u = graph[start][i];
		if (!visited[u])
			Topology(u);
	}
	st.push(start);
}
void Indegree()
{
	int v, u;
	
	for (int i = 1; i < graph.size(); ++i){
		if (in[i] == 0)
			q.push(i);
	}
	while (!q.empty()){
		v = q.front();
		printf("%d ", v);
		q.pop();

		for (int i = 0; i < graph[v].size(); ++i){
			u = graph[v][i];
			in[u]--;
			if (in[u] == 0)
				q.push(u);
		}
	}
}
void Print()
{
	while (!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
}