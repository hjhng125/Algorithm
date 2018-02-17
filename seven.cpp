#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n;
	float grade;
	vector<float> v;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i){
		scanf("%f", &grade);
		v.push_back(grade);
		if (v.size() > 7){
			sort(v.begin(), v.end());
			v.pop_back();
		}
	}
	for (int i = 0; i < v.size();i++)
		printf("%.3f\n",v[i]);
	return 0;
}
