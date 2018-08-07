#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, num[1000] = { 0, };
		scanf("%d", &n);
		double total = 0.0;
		double avg;
		for (int i = 0; i < n; ++i) {
			scanf("%d", num + i);
			total += num[i];
		}
		avg = total / n;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (num[i] > avg)
				cnt++;
		}
		printf("%0.3f%%\n", (cnt/(double)n)*100.0);
	}
}