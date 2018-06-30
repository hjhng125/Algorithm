#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, c;
vector<int> home;
bool search(int mid)
{
	int num = 1;
	int start = home[0];
	for (auto i : home) {
		if (i - start >= mid) { // �����⸦ ��ġ�� �� �ִ� �� ã��
			num++;
			start = i; // �ش� ��ġ�� �����⸦ ��ġ
		}
	}
	return num < c;
}
int main()
{
	scanf("%d %d", &n, &c);
	home.resize(n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &home[i]);
	}
	sort(home.begin(), home.end());

	int left = 1;
	int right = home[n - 1] - home[0];
	int result;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (search(mid))
			right = mid - 1;
		else {
			left = mid + 1;
			result = mid;
		}	
	}
	printf("%d", result);
}