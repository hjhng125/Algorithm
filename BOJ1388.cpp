#include<cstdio>

using namespace std;

int n, m, result = 0;
char f[101][101];
void horizon(int nextX, int nextY){

	if (f[nextX][nextY] != '*'){
		if (f[nextX][nextY] == '-'){
			f[nextX][nextY] = '*';
			horizon(nextX, nextY + 1);
		}

	}
}
void vertical(int nextX, int nextY){

	if (f[nextX][nextY] != '*'){
		if (f[nextX][nextY] == '|'){
			f[nextX][nextY] = '*';
			vertical(nextX + 1, nextY);
		}
		return;

	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
		scanf(" %c", &f[i][j]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (f[i][j] != '*'){
				if (f[i][j] == '-'){
					f[i][j] = '*';
					horizon(i, j + 1);
				}
				else if (f[i][j] == '|'){
					f[i][j] = '*';
					vertical(i + 1, j);
				}
				result++;
			}
		}
	}
	printf("%d", result);

	return 0;
}
