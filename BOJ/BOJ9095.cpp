#include<cstdio>
#include<vector>
using namespace std;

int t, n;
int arr[12];
int main()
{
	scanf("%d", &t);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 11; ++i) {
		for (int j = i - 3; j < i; ++j) {
			arr[i] += arr[j];
		}
	}
	while(t > 0){
		scanf("%d", &n);
		printf("%d",arr[n]);
		t--; 
	}
}