#include<cstdio>
#include<algorithm>

using namespace std;

int n, cnt;
int box[1001], result[1001];
bool visit[1001];

// 현재크기의 상자가 담길 수 있는지 확인
void solution(int cur) {

	for (int next = cur + 1; next <= n; ++next) {
		if (box[cur] >= box[next]) continue;
		
		//다음 상자가 현재상자를 넣는 것의 최대값을 저장한다.
		result[next] = max(result[next], result[cur] + 1);
	}

}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &box[i]);
	}
	int maxV = 0;

	fill(result + 1, result + n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		solution(i);
	}
	for (int i = 1; i <= n; ++i) {
		maxV = max(maxV, result[i]);
	}
	printf("%d", maxV);

}