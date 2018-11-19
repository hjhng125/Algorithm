#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct NODE {
	float x, y, angle;
}Node;
Node* node;
Node* hall;
int tc, n, start;

float get_dist(Node a, Node b) {
	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}
int orientation(Node p1, Node p2, Node p3) {
	int result;

	return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}
int jarvis() {
	int cur = start, next;
	int idx = 1;
	
	do {
		if (idx > n) {
			printf("Not convex hall");
			exit(1);
		}
		hall[idx++] = node[cur];
		next = (cur + 1) % n;
		for (int i = 1; i <= n; ++i) {
			if (orientation(node[cur], node[i], node[next]) > 0)
				next = i;
		}
		cur = next;
	} while (cur != start);
	return idx-1;
}
float get_area(int idx) {
	float a = 0.0, b = 0.0;
	for (int i = 0; i < idx; ++i) {
		a += hall[i].x * hall[i + 1].y;
		b += hall[i + 1].x * hall[i].y;
	}
	a += hall[idx].x * hall[0].y;
	b += hall[idx].y * hall[0].x;

	return (a - b) / 2.0;
}
int main()
{
	scanf("%d", &tc);
	while (tc--) {
		float dist = 2.0;
		scanf("%d", &n);
		node = (Node*)malloc(sizeof(Node) * (n + 1));
		hall = (Node*)malloc(sizeof(Node) * (n + 1));
		for (int i = 1; i <= n; ++i) {
			scanf("%f %f", &node[i].x, &node[i].y);
			if (i == 1)
				start = i;
			else if (node[i].y < node[start].y)
				start = i;
		}
		hall[0].x = 0;
		hall[0].y = 0;
		int idx = jarvis();
		for (int i = 0; i < idx ; ++i)
			dist += get_dist(hall[i], hall[i + 1]);
		dist += get_dist(hall[idx], hall[0]);
		printf("%.2f %.2f", dist, get_area(idx));
	}
}
/*
1
4
1.0 1.0
-1.0 1.0
-1.0 -1.0
1.0 -1.0

1 
6
1.0 1.0
2.0 2.0
3.0 3.0
-1.0 -1.0
-2.0 -2.0
-3.0 -3.0

1
4
3 2
0 3
1 -1
1 -2
*/