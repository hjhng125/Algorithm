#include<cstdio>
#include<algorithm>

using namespace std;

int n, cnt;
int box[1001], result[1001];
bool visit[1001];

// ����ũ���� ���ڰ� ��� �� �ִ��� Ȯ��
void solution(int cur) {

	for (int next = cur + 1; next <= n; ++next) {
		if (box[cur] >= box[next]) continue;
		
		//���� ���ڰ� ������ڸ� �ִ� ���� �ִ밪�� �����Ѵ�.
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