#include<cstdio>
#include<queue>
#include<functional>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;
int n, k; // 보석 수, 가방수
int m, v; // 보석 무게, 가격 
long long cNum;
vector<long long> c;
vector<pi> j;

struct compareValue {
	bool operator()(pi x, pi y) {
		return x.second < y.second;
	}
};
priority_queue<pi, vector<pi>, compareValue> pq;

int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &m ,&v);
		j.push_back(make_pair(m, v));
	}

	for (int i = 0; i < k; ++i) {
		scanf("%lld", &cNum);
		c.push_back(cNum);
	}
	sort(j.begin(), j.end());
	sort(c.begin(), c.end());
	
	long long total = 0;
	
	for (int i = 0, idx = 0; i < k; ++i) {
		while (idx < n && c[i] >= j[idx].first) {
			pq.push(make_pair(j[idx].first, j[idx].second));
			idx++;
		}
		if (!pq.empty()) {
			total += pq.top().second;
			pq.pop();
		}
	}
	printf("%lld",total);
}