#include<cstdio>
using namespace std;

int arr[2001];
int palin[2001][2001];
int main()
{
	int n;
	scanf("%d" ,&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
		palin[i][i] = 1;
	}
	
	for (int i = 1; i <= n; ++i) {
		//If range odd
		int l = i;
		int r = i;
		while(l > 0 && r <= n && arr[l] == arr[r]){
				palin[l][r] = 1;
				l--;
				r++;
		}
		//If range is even
		l = i;
		r = i + 1;
		while (l > 0 && r <= n && arr[l] == arr[r]) {
			palin[l][r] = 1;
			l--;
			r++;
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 1;i <= q; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		if (palin[s][e])
			printf("1\n");
		else 
			printf("0\n");
	}
}