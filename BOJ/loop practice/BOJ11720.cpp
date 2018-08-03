#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int c, sum = 0;
	scanf("%d", &c);
	vector<char> num(c + 1);
	for (int i = 0; i < c; ++i) {
		scanf(" %c", &num[i]);
		int n;
		sum += num[i] - '0';
	}
	printf("%d", sum);
}
