#include<cstdio>
#include<vector>
#define MAX 101
using namespace std;

int n;
int adj[MAX][MAX];
int result[MAX][MAX];
bool visited[MAX];
void initVisited(){
	for (int i = 1; i <= n; ++i){
		visited[i] = false;
	}
}
void DFS(int u){
	for (int j = 1; j <= n; ++j){
		if (adj[u][j] && !visited[j]){
			visited[j] = true; // 현재위치가 아닌 앞으로 갈 위치를 확인
			DFS(j);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
			scanf("%d", &adj[i][j]);
	}
	for (int i = 1; i <= n; ++i){
		initVisited(); // 노드마다 DFS를 돌리기 때문에 초기화
		DFS(i); // 노드마다 DFS로 어디를 갈 수 있는 지 확인
		for (int j = 1; j <= n; ++j)
			result[i][j] = visited[j]; // 각 노드마다 방문한 곳을 result에 넣음
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
			printf("%d ",result[i][j]);
		printf("\n");
	}
	return 0;
}