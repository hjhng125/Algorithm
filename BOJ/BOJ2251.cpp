#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

// a, b ,c 물통의 현재 량 
typedef struct bot {
	int a, b, c;
};
int visit[201][201][201];
int main()
{
	// a, b, c 물통의 용량
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	
	queue<bot> q;
	q.push({ 0, 0, c });
	vector<int> ans;
	
	// 현재 있는 양을 보며 계속 나아감
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (visit[cur.a][cur.b][cur.c])
			continue;
		visit[cur.a][cur.b][cur.c] = 1;

		if (cur.a == 0) 
			ans.push_back(cur.c);

		
		if (cur.a + cur.b > b)
			q.push({ cur.a + cur.b - b, b, cur.c });
		else
			q.push({ 0, cur.a + cur.b, cur.c });

		if (cur.a + cur.c > c)
			q.push({ cur.a + cur.c - c, cur.b, c });
		else
			q.push({ 0, cur.b, cur.a + cur.c });
		
		if (cur.b + cur.a > a)
			q.push({ a, cur.b + cur.a - a, cur.c });
		else
			q.push({ cur.a + cur.b, 0, cur.c });
		
		if (cur.b + cur.c > c)
			q.push({ cur.a, cur.b + cur.c - c, c });
		else
			q.push({ cur.a, 0, cur.c + cur.b });
		
		if (cur.c + cur.a > a)
			q.push({ a, cur.b, cur.c + cur.a - a });
		else
			q.push({ cur.a + cur.c, cur.b, 0 });
		
		if (cur.c + cur.b > b)
			q.push({ cur.a, b, cur.c + cur.b - b });
		else
			q.push({ cur.a, cur.b + cur.c, 0 });
	}

	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d\n", ans[i]);
	}
	
}