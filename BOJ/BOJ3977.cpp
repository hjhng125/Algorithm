#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 100000
using namespace std;

int v, e, cnt, sccNum;
vector<vector<int> > adj;
vector<int> dfsn, finished, sn;
stack<int> s;
int dfs(int cur) {
	dfsn[cur] = ++cnt;
	s.push(cur);
	int result = dfsn[cur];
	for (auto next : adj[cur]) {
		if (!dfsn[next]) {
			result = min(result, dfs(next));
		}
		else if (!finished[next]) {
			result = min(result, dfsn[next]);
		}
	}
	if (result == dfsn[cur]) {
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = 1;
			sn[t] = sccNum;

			if (t == cur)
				break;
		}
		sccNum++;
	}
	return result;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &v, &e);
		adj.clear();
		dfsn.clear();
		finished.clear();
		sn.clear();
		adj.resize(MAX);
		dfsn.resize(MAX);
		finished.resize(MAX);
		sn.resize(MAX);
		cnt = 0;
		sccNum = 0;
		for (int i = 1; i <= e; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}
		for (int i = 0; i < v; ++i) {
			if (!dfsn[i])
				dfs(i);
		}
		int check[MAX] = {0, };
		for (int i = 0; i < v; ++i) {
			for (int j : adj[i]) {
				if (sn[i] == sn[j])
					continue;
				check[sn[j]]++;
			}
		}
		int target, cntdegree = 0;
		for (int i = 0; i < sccNum; ++i) {
			if (!check[i]){
				target = i;
				cntdegree++;
			}
		}
		if(cntdegree > 1)
			printf("Confused\n");
		else {
			for (int i = 0; i < v; ++i) {
				if (sn[i] == target)
					printf("%d\n", i);
			}
		}
		printf("\n");
	}
}