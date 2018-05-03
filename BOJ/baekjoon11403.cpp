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
			visited[j] = true; // ������ġ�� �ƴ� ������ �� ��ġ�� Ȯ��
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
		initVisited(); // ��帶�� DFS�� ������ ������ �ʱ�ȭ
		DFS(i); // ��帶�� DFS�� ��� �� �� �ִ� �� Ȯ��
		for (int j = 1; j <= n; ++j)
			result[i][j] = visited[j]; // �� ��帶�� �湮�� ���� result�� ����
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
			printf("%d ",result[i][j]);
		printf("\n");
	}
	return 0;
}