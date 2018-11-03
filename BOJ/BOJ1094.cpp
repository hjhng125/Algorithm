#include<cstdio>
#include<string>
using namespace std;

int x, cur[9], cnt;
int main()
{
	fill(cur, cur + 9, -1);
	scanf("%d", &x);
	int i = 0;
	while (x) {
		cur[i] = x % 2;
		x /= 2;
		if (cur[i])
			cnt++;
		i++;
	}
	printf("%d", cnt);
}