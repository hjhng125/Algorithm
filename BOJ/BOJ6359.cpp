#include<cstdio>
#include<vector>

using namespace std;

int t, n;
vector<int> ans;
int solution(int n) {
	vector<int> room;
	room.resize(n + 1, 1);
	for (int i = 2; i <= n; ++i) {
		for (int j = i; j <= n; j = j + i) {
			if (room[j] == 1)
				room[j] = 0;
			else
				room[j] = 1;
		}
	}
	int result = 0;
	for (int i = 1; i <= n; ++i) {
		if (room[i] == 1)
			result++;
	}
	return result;
}
int main()
{
	scanf("%d",&t);
	ans.resize(t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		ans[i] = solution(n);
	}
	for (int i = 0; i < ans.size(); ++i)
		printf("%d\n", ans[i]);
}
