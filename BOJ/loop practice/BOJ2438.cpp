#include<cstdio>

using namespace std;

int main()
{
	int n;
	
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (cnt >= j)
				printf(" ");
			else
				printf("*");
		}
		cnt++;
		printf("\n");
	}
}
