#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<vector<int> > adj;
vector<vector<int> > tree;
vector<bool> visit;
int dp[1000001][2];
int n;			
void makeTree(int cur) {
	visit[cur] = true;
	for (int next : adj[cur]) {
		if (!visit[next]) {
			tree[cur].push_back(next);
			makeTree(next);
		}
	}
}
int dfs(int cur, int flag) {
	if (dp[cur][flag] != -1)
		return dp[cur][flag];

	if (flag) {
		dp[cur][flag] = 1;
		for (int next : tree[cur]) {
			dp[cur][flag] += min(dfs(next, 0), dfs(next, 1));
		}
	}
	else {
		dp[cur][flag] = 0;
		for (int next : tree[cur]) {
			dp[cur][flag] += dfs(next, 1);
		}
	}
	return dp[cur][flag];
}
int main()
{
	scanf("%d", &n);
	
	adj.resize(n + 1);
	visit.resize(n + 1);
	tree.resize(n + 1);
	for (int i = 1; i < n; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	makeTree(1);
	memset(dp, -1, sizeof(dp));
	printf("%d\n",min(dfs(1,0), dfs(1,1)));
}