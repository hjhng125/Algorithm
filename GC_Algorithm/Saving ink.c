#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

typedef struct VERTEX {
	float x, y;
	int idx;
}vertex;
typedef struct EDGE {
	vertex cur, next;
	float weight;
}edge;
vertex vt[31];
edge *e;
int parent[31];
int tc, v_num;
float answer;

void sort() {
	for (int i = 1; i <= v_num; ++i) {
		for (int j = 1; j < v_num - (i - 1); ++j) {
			if (e[j].weight > e[j + 1].weight) {
				edge temp = e[j];
				e[j] = e[j + 1];
				e[j + 1] = temp;
			}
		}
	}
}

int find_set(int idx) {
	if (parent[idx] == idx)
		return parent[idx];
	return parent[idx] = find_set(parent[idx]);
}

void union_set(edge eg) {
	int u = find_set(eg.cur.idx);
	int v = find_set(eg.next.idx);
	
	if (u == v)
		return;
	parent[u] = v;
	answer += eg.weight;
}

int main()
{
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &v_num);
		e = (edge *)malloc(sizeof(edge) * (v_num * (v_num - 1) / 2));
		
		for (int i = 1; i <= v_num; ++i) {
			scanf("%f %f", &vt[i].x, &vt[i].y);
			vt[i].idx = i;
		}
		int k = 1;
		for (int i = 1; i <= v_num; ++i) {
			for (int j = i; j <= v_num; ++j) {
				if (i == j) continue;
				e[k].cur = vt[i];
				e[k].next = vt[j];
				e[k].weight = sqrt(pow(e[k].cur.x - e[k].next.x, 2) + pow(e[k].cur.y - e[k].next.y, 2));
				k++;
			}
		}
		sort();
		for (int i = 1; i <= (v_num * (v_num - 1) / 2); ++i)
			parent[i] = i;

		for (int i = 1; i <= (v_num * (v_num - 1) / 2); ++i) {
			union_set(e[i]);
		}
		printf("%.2f\n", answer);
	}
}
/*
1
3
1.0 1.0
2.0 2.0
2.0 4.0
*/





