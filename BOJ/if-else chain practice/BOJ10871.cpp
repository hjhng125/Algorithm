#include<cstdio>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	for (int i = 0; i < a; ++i) {
		int num;
		scanf("%d", &num);
		if (num < b)
			printf("%d ", num);
	}
}