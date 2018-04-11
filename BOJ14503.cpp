#include<cstdio>
#include<cstdlib>
#define MAX 50
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int visit[MAX][MAX];
int n, m;
int r, c, d;
int count = 0;

void search(int y, int x, int d){
	int flag = 1;
	int nextx, nexty;
	int i;

	while (flag){		
		if (!visit[y][x]){
			visit[y][x] = 2;
			count++;
		}
		for (i = 0; i < 4; ++i){
			nextx = x + dx[(d + 3) % 4];
			nexty = y + dy[(d + 3) % 4];
			if (visit[nexty][nextx] == 0){
				x = nextx;
				y = nexty;
				d = (d + 3) % 4;
				break;
			}
			d = (d + 3) % 4;
		}
		if (i == 4){
			x += dx[(d + 2) % 4];
			y += dy[(d + 2) % 4];
		}
		if (visit[y][x] == 1)
			flag = 0;
	}
}
int main(){

	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
		scanf("%d", &visit[i][j]);
	
	search(r, c, d);
	printf("%d", count);

	return 0;
}
