#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int in, out;
	int cnt = 0, maxC = 0;
	for (int i = 1; i <= 4; ++i) {
		scanf("%d %d", &out, &in);
		cnt += in;
		cnt -= out;
		maxC = max(maxC, cnt);
	}
	printf("%d", maxC);
}