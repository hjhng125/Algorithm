#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > arr;
int h;
int main()
{
	scanf("%d", &h);
	arr.resize(h + 1);
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= i; ++j) {
			int n;
			scanf("%d", &n);
			arr[i].push_back(n);
		}
	}
	int maxV = 0;
	for (int i = 1; i <= h; ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			if (i == 1) continue;
			if (j == 0) {
				arr[i][j] += arr[i - 1][j];
			}
			else if (j == arr[i].size() - 1) {
				arr[i][j] += arr[i - 1][j - 1];
			}
			else {
				arr[i][j] += max(arr[i-1][j], arr[i-1][j-1]);
			}
			if (i == h) {
				maxV = max(arr[i][j], maxV);
			}
		}
	}

	printf("%d", maxV);
}