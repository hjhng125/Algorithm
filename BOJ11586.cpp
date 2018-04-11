#include<cstdio>
using namespace std;

int n, k;
char mirror[101][101];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			scanf(" %c", &mirror[i][j]);
	}
	scanf("%d", &k);
	if (k == 1){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				printf("%c", mirror[i][j]);
			printf("\n");
		}
	}
	else if (k == 2){
		for (int i = 0; i < n; ++i){
			for (int j = n - 1; j >= 0; --j)
				printf("%c",mirror[i][j]);
			printf("\n");
		}
	}
	else if (k == 3){
		for (int i = n - 1; i >= 0; --i){
			for (int j = 0; j < n; ++j)
				printf("%c", mirror[i][j]);
			printf("\n");
		}
	}

}