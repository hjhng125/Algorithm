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

	// 입력한 숫자와 index를 맞추기 위하여 +1 시켜줌
	graph.resize(n + 1);
	visited.resize(n + 1, 0); // vector의 크기를 n+1로, 안의 값들은 0으로 초기화
	in.resize(n + 1, 0);      // (인접점이 있어야 한다 -> 백준알고리즘 답안에 맞추기 위한 조건)

	for (int i = 0; i < m; ++i){
		scanf("%d %d", &v, &u);
		graph[v].push_back(u);
		in[u]++; // indegree 체크
	}
	for (int i = 1; i <= n; ++i){ // 모든 점들을 확인 -> 연결되어 있지 않는 점들의 확인을 위해
		if (!visited[i] && !graph[i].empty()) // 방문하지 않은 점이어야 한다
			Topology(i);
	}
	Print();
	Indegree();
}
void Topology(int start)
{
	visited[start] = 1; // 점을 방문하면 visited에 체크

	for (int i = 0; i < graph[start].size(); ++i){
		int u = graph[start][i]; // 현재 점에 연결된 점 확인
		if (!visited[u]) // 방문한 점이 아니라면 재귀함수 호출
			Topology(u);
	}
	st.push(start); // 스택에 넣고 차례대로 pop하면 위상정렬된 리스트를 볼 수 있음
}
void Indegree()
{
	int v, u;
	
	for (int i = 1; i < graph.size(); ++i){ // 정점들중에서 indegree가 0인것들을 queue에 저장
		if (in[i] == 0)
			q.push(i);
	}
	while (!q.empty()){ // queue가 빈 경우는 sort가 끝난경우이거나 cycle이 있는 경우이다.
		v = q.front(); 
		printf("%d ", v);
		q.pop();

		for (int i = 0; i < graph[v].size(); ++i){
			u = graph[v][i]; // queue에서 삭제한 점과 indegree로써 연결된 점
			in[u]--; // 간선 삭제
			if (in[u] == 0) // 간선 삭제 후 indegree가 0이 된 점을 queue에 삽입
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
