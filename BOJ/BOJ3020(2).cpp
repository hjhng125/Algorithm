#include<cstdio>
#include<algorithm>
#include<functional>

#define MAX 200001

using namespace std;

int n, h;
int suck[MAX / 2 + 1], jong[MAX / 2 + 1];
int answer[MAX];
int solution_s(int height)
{
	int left = 1, right = n / 2;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (suck[mid] < height) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return n/2 - right;
}
int solution_j(int height)
{
	int left = 1, right = n / 2;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (jong[mid] >= height) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return n/2 - right;
}
int main()
{
	scanf("%d %d", &n, &h);

	for (int i = 1; i <= n; ++i) {
		if (i % 2)
			scanf("%d", suck + (i / 2) + 1);
		else {
			scanf("%d", jong + i / 2);
			jong[i / 2] = h - jong[i / 2];
		}
	}
	sort(suck + 1, suck + (n / 2) + 1);
	sort(jong + 1, jong + (n / 2) + 1, greater<int>());

	for (int i = 1; i <= h; ++i) {
		answer[solution_s(i) + solution_j(i)]++;
	}
	for (int i = 0; i < n; ++i) {
		if (answer[i]) {
			printf("%d %d", i, answer[i]);
			break;
		}
	}
	return 0;
}