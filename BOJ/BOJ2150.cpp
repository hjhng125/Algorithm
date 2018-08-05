#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int v, e, cnt, sccNum;
vector<vector<int> > adj, organization;
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
		vector<int> curScc;
		while (1) {
			int t = s.top();
			s.pop();
			curScc.push_back(t);
			finished[t] = 1;
			sn[t] = sccNum;

			if (t == cur)
				break;
		}
		sort(curScc.begin(), curScc.end());
		organization.push_back(curScc);
		sccNum++;
	}
	return result;
}
int main()
{
	scanf("%d %d", &v, &e);
	adj.resize(v + 1);
	dfsn.resize(v + 1);
	finished.resize(v + 1);
	sn.resize(v + 1);
	for (int i = 1; i <= e; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= v; ++i) {
		if (dfsn[i] == 0)
			dfs(i);
	}
	sort(organization.begin(), organization.end());
	printf("%d\n",sccNum);
	for (auto curScc : organization) {
		for (auto cur : curScc) {
			printf("%d ", cur);
		}
		printf("-1\n");
	}
}