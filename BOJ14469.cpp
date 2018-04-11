#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<pii> line;
int n;
int a_second, t_second;
int main(int argc, char* arfv[])
{
	int total = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &a_second, &t_second);
		line.push_back(make_pair(a_second, t_second));
	}
	sort(line.begin(), line.end());
	for (int i = 0; i < n; ++i){
		if (total < line[i].first)
			total = line[i].first + line[i].second;
		else total += line[i].second;
	}
	printf("%d", total);
	
	return 0;
}