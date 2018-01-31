#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 1e9

int sweep();

vector<pair<int, int> > vt;
int c;

int main()
{
	int s, e;

	scanf("%d",&c);
	for (int i = 0; i < c; ++i){
		scanf("%d %d", &s, &e);
		vt.push_back(make_pair(s, e));
	}
	sort(vt.begin(),vt.end()); // 원활한 sweeping을 위해 정렬

	printf("%d",sweep());
	return 0;
}
int sweep()
{
	int l, r, result = 0;

	l = -INF;
	r = -INF;
	for (int i = 0; i < c; i++){
		if (r < vt[i].first){ // 범위가 겹치지 않은 새로운 범위일때
			result += r - l; // 새로운 범위를 입력 전 전의 범위값
			l = vt[i].first;
			r = vt[i].second;
		}
		else r = max(r, vt[i].second); //범위가 겹칠 때 범위 최신화
	}
	result += r - l; // 마지막에 추가된 범위의 값도 넣어줌
	return result;
}
