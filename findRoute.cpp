#include<cstdio>
#include<vector>
using namespace std;

void warshall();
int n;
vector<vector<int> > adj;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i){
		vector<int> ele;
		ele.resize(n + 1);
		adj.push_back(ele);
	}
	int u;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			scanf("%d", &u);
			adj[i][j] = u;
		}
	}
	warshall();
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void warshall()
{
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				adj[i][j] = adj[i][j]|(adj[i][k] & adj[k][j]);
			}
		}
	}
}