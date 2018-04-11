#include<cstdio>
#include<vector>

using namespace std;

int n;
vector<int> cow;
int main()
{
	int cowNum, direction;
	int count = 0;
	scanf("%d", &n);
	cow.resize(n + 1, -1);
	for (int i = 1; i <= n; ++i){
		scanf("%d %d", &cowNum, &direction);
		if (cow[cowNum] != -1 && cow[cowNum] != direction)
			count++;
		cow[cowNum] = direction;
	}
	printf("%d", count);
	return 0;
}