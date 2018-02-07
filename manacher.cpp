#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

char str[100000];
vector<string> arr;
vector<int> a;
int main()
{	
	int idx;
	scanf("%s",str);
	int n = strlen(str);
	arr.resize(n * 2 + 1);
	for (idx = 0; idx < n; ++idx){	
		arr[idx * 2 + 1] = str[idx];
		arr[idx*2] = '#';
	}
	arr[idx * 2] = '#';
	
	a.resize(n * 2 + 1);
	int r, p; // r : 현재 인덱스에서 형성되어있는 팰린드롬의 마지막 인덱스
	r = 0; p = 0; // p : 그 r의 팰린드롬의 중심 
	for (int i = 0; i < arr.size(); ++i){
		if (r >= i) // i가 팰린드롬 안에 있을 경우
			a[i] = min(r - i, a[2 * p - i]); // r-i : i기준 해당 팰린드롬 내의 보장되어있는 범위, a[2*p-i] : i'(p를 대칭으로 i의 대칭점)의 보장된 범위  
		else // i가 팰린드롬 밖에 있을 경우
			a[i] = 0;
		while (i - a[i] - 1 >= 0 && i + a[i] + 1 < arr.size() && arr[i - a[i] - 1] == arr[i + a[i] + 1]) a[i]++;
		if (r < i + a[i]){ // 팰린드롬의 길이 update 
			r = i + a[i];
			p = i;
		}
	}
	int maxr = 0;
	for (int i = 0; i < arr.size(); ++i)
		maxr = max(maxr,a[i]);
	printf("%d\n",maxr);
	
	return 0;
}