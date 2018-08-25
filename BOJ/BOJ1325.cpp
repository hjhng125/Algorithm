/*
pair로 현재 node의 연결된 수를 찾다보니 제대로된 노드를 
찾을 수 없어 고민한 문제
*/
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<int> ans;

int main()
{
	scanf("%d %d", &n, &m);
	adj.resize(n + 2);
	ans.resize(n + 2);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[b].push_back(a);
	}
	
	int maxV = 0;
	for (int i = 1; i <= n; ++i) {
		queue<int> q;
		q.push(i);
		int cnt = 0;
		vector<bool> visit(n + 2, false);
		visit[i] = true;		
		
		while (!q.empty()) {
			int cur = q.front();
			
			q.pop();

			for (int next : adj[cur]) {
				if (visit[next]) 
					continue;
				q.push(next);
				cnt++;
				visit[next] = true;
			}
		}
		ans[i] = cnt;
		maxV = max(maxV, ans[i]);
	}

	for (int i = 1; i <= n; ++i) {
		if(maxV == ans[i])
			printf("%d ", i);
	}

}