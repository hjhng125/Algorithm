#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct NODE {
	float x, y, angle;
}Node;
Node* node;
Node* stack;
int top = 0;
int tc, n, start;

void push(Node node) {
	if (top > n) {
		printf("stack full");
		exit(1);
	}
	stack[++top] = node;
}
void pop() {
	if (top < 0) {
		printf("stack empty");
		exit(1);
	}
	top--;
}
void swap(int start) {
	Node tmp = node[start];
	node[start] = node[1];
	node[1] = tmp;
}
float calculateAngle(Node x) {
	float dx, dy;
	float angle;

	dx = x.x - node[1].x;
	dy = x.y - node[1].y;

	if (dx >= 0 && dy == 0) angle = 0.0;
	else {
		angle = (float)abs(dy) / (abs(dx) + abs(dy));
		if (dx < 0 && dy >= 0) angle = 2 - angle;
		else if (dx <= 0 && dy < 0) angle = 2 + angle;
		else if (dx > 0 && dy < 0) angle = 4 - angle;
	}
	return angle * 90.0;
}
void sort(int s, int e) {
	for (int i = s; i <= e; ++i) {
		for (int j = s; j <= e - s + 1; ++j) {
			if (node[j].angle > node[j + 1].angle) {
				Node tmp = node[j];
				node[j] = node[j + 1];
				node[j + 1] = tmp;
			}
		}
	}
}
int CCW(Node one, Node two, Node three) {
	return (one.x * two.y + two.x * three.y + three.x * one.y) - (one.y * two.x + two.y * three.x + three.y * one.x);
}
void graham_scan() {
	for (int i = 1; i <= 2; ++i) {
		push(node[i]);
	}
	for (int i = 3; i <= n; ++i) {
		while (CCW(stack[top - 1], stack[top], node[i]) <= 0) {
			pop();
		}
		push(node[i]);
	}
}
float get_dist(Node a, Node b) {
	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}
float get_area() {
	float a = 0.0, b = 0.0;
	for (int i = 0; i < top; ++i) {
		a += stack[i].x * stack[i + 1].y;
		b += stack[i + 1].x * stack[i].y;
	}
	a += stack[top].x * stack[0].y;
	b += stack[top].y * stack[0].x;

	return (a - b) / 2.0;
}
int main()
{

	scanf("%d", &tc);
	while (tc--) {
		float dist = 2.0;
		scanf("%d", &n);
		node = (Node*)malloc(sizeof(Node) * (n + 1));
		stack = (Node*)malloc(sizeof(Node) * (n + 1));

		for (int i = 1; i <= n; ++i) {
			scanf("%f %f", &node[i].x, &node[i].y);
			if (i == 1)
				start = i;
			else if (node[i].y < node[start].y)
				start = i;
		}
		swap(start);
		for (int i = 2; i <= n; ++i)
			node[i].angle = calculateAngle(node[i]);
		sort(2, n);

		stack[0].x = 0.0;
		stack[0].y = 0.0;
		graham_scan();

		for (int i = 0; i < top; ++i)
			dist += get_dist(stack[i], stack[i + 1]);
		dist += get_dist(stack[top], stack[0]);
		printf("%.2f %.2f", dist, get_area());
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