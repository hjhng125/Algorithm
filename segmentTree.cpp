#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

long long makeTree(int, int, int);
void change(int, int, int, int, int);
long long sum(int, int, int, int, int);
vector<int> arr;
vector<long long> tree;
vector<long long> total;
int n, m, k;
int main()
{
	int input,tmp;
	int a, b, c;

	scanf("%d %d %d", &n, &m, &k);
	arr.resize(n + 1);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &input);
		arr[i] = input;
	}
	int h = (int)ceil(log2(n + 1));
	tree.resize((int)pow(2, h + 1) + 1);
	makeTree(1, 1, n);
	while (m != 0 || k != 0){
		scanf("%d %d %d", &a, &b, &c); // b번째 수를 c로 업데이트
		if (a == 1){
			change(1, 1, n, b, c - arr[b]); //nodeNum,바꿀인덱스,바꿀값
			arr[b] = c;
			m--;
		}
		else if(a == 2){
			total.push_back(sum(1, 1, n, b, c));
			k--;
		}
	}
	for (int i = 0; i < total.size(); ++i)
		printf("%lld\n",total[i]);
	return 0;
}
long long makeTree(int nodeNum, int start, int end)
{
	if (start == end)
		return tree[nodeNum] = arr[start];
	
	int mid = (start + end) / 2;

	return tree[nodeNum] = makeTree(nodeNum * 2, start, mid) + makeTree(nodeNum * 2 + 1, mid + 1, end);
}
void change(int nodeNum, int start, int end, int changeIdx, int diff)
{
	if (!(start <= changeIdx && changeIdx <= end))
		return;
	tree[nodeNum] += diff;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	change(nodeNum * 2, start, mid, changeIdx, diff);
	change(nodeNum * 2 + 1, mid + 1, end, changeIdx, diff);
}
long long sum(int nodeNum, int start, int end, int sumL, int sumR)
{
	if (end < sumL || sumR < start)
		return 0;
	else if (sumL <= start && end <= sumR)
		return tree[nodeNum];

	int mid = (start + end) / 2;
	return sum(nodeNum * 2, start, mid, sumL, sumR) + sum(nodeNum * 2 + 1, mid + 1, end, sumL, sumR);
}