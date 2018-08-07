#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int n;
	float num[1000], maxNum = 0.0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%f", num + i);
		maxNum = max(maxNum, num[i]);
	}
	float total = 0.0, avg;
	for (int i = 0; i < n; ++i) {
		total += (num[i] / maxNum * 100.0);
	}
	avg = total / n;
	printf("%f", avg);
}