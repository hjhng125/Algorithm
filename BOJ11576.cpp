#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int a, b;
int n;
int input, total = 0;
vector<int> result;
int main()
{
	scanf("%d %d", &a, &b);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &input);
		total += input * pow(a, n - (i + 1));
	}
	while (total){
		result.push_back(total % b);
		total /= b;
	}
	for (int i = result.size() - 1; i >= 0; --i)
		printf("%d ",result[i]);
}