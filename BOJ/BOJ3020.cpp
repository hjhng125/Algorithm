#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, h;
int lc, rc;
int c[200001], m_c1[500001], m_c2[500001];
vector<int> min1;
//counting sort로 높이마다 뚫어야 할 개수 구해놈
void mSort() {
	lc = 1;
	rc = 1;
	for (int i = 1; i <= n; ++i) {
		if (i % 2) {
			m_c1[c[i]]++;
		}
		else {
			m_c2[h - c[i]]++;
		}
	}
}
void sol() {
	int cnt1, cnt2;

	for (int i = 1; i <= h; ++i) {
		if (i == 1) {
			cnt1 = n / 2;
			cnt2 = 0;
		}
		else if (i == h) {
			cnt1 = 0;
			cnt2 = n / 2;
		}
		else {
			cnt1 -= m_c1[i - 1];
			cnt2 += m_c2[i - 1];
		}
		min1[cnt1 + cnt2]++;
	}
	
}
int main()
{
	scanf("%d %d", &n, &h);
	min1.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	mSort();
	sol();
	for (int i = 0; i <= n; ++i) {
		if (min1[i]) {
			printf("%d %d", i, min1[i]);
			break;
		}
	}
	return 0;
}