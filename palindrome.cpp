#include<cstdio>
#include<algorithm>
#define MAX 2001
using namespace std;
int palin();
int n, m;
int start, e;
int a[MAX];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d",&a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i){
		scanf("%d %d", &start, &e);
		printf("%d\n",palin());
	}
	return 0;
}
int palin()
{
	int mid = (start + e) / 2;
	// 정해진 범위에서 앞과 뒤에서 하나씩 감소하며 팰린드롬인지 확인
	for (int idx1 = start, idx2 = e; idx1 <= mid, idx2 >= mid; idx1++, idx2--){  
		if (a[idx1] == a[idx2])
			continue;
		else return 0;
	}
	return 1;
}