#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct POINT {
	float x, y, angle;
}point;
point* p, *stack;

int n, top;
float dist = 2.0;

// swap first and start point
void swap(int start) {
	point tmp = p[start];
	p[start] = p[1];
	p[1] = tmp;
}
// sort by array of point
void sort() {
	for (int i = 2; i < n; ++i) {
		for (int j = 2; j <= n - i + 1; ++j) {
			if (p[j].angle > p[j + 1].angle) {
				point tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}
// sort by stack
void sort_stack() {
	for (int i = 0; i < top; ++i) {
		for (int j = 0; j <= top - (i + 1); ++j) {
			if (stack[j].angle > stack[j + 1].angle) {
				point tmp = stack[j];
				stack[j] = stack[j + 1];
				stack[j + 1] = tmp;
			}
		}
	}
}
// function of stack
void push(point in) {
	if (top > n) {
		printf("Fulled stack");
		exit(1);
	}
	stack[++top] = in;
}
// function of stack
void pop() {
	if (top < 0) {
		printf("Emptyed stack");
		exit(1);
	}
	top--;
}
// check three point whether CCW or not
// if return less than 0, this is CW
int orientation(point nextTop, point top, point cur) {
	return (nextTop.x*top.y + top.x*cur.y + cur.x*nextTop.y) - (nextTop.y*top.x + top.y*cur.x + cur.y*nextTop.x);
}

// calculate angle
float calculate_angle(point po) {
	float dx, dy, angle;
	
	dx = po.x - p[1].x;
	dy = po.y - p[1].y;

	if (dx >= 0 && dy == 0)
		angle = 0.0;
	else {
		angle = (float)abs(dy) / (abs(dx) + abs(dy));
		if (dx < 0 && dy >= 0)
			angle = 2.0 - angle;
		else if (dx < 0 && dy <= 0)
			angle = 2.0 + angle;
		else if (dx > 0 && dy < 0)
			angle = 4.0 - angle;
	}
	return angle * 90.0;
}

void graham_scan() {
	push(p[1]);
	push(p[2]);
	for (int i = 3; i <= n; ++i) {
		while (orientation(stack[top - 1], stack[top], p[i]) < 0) // if not CCW, pop
			pop();
		push(p[i]);
	}
}
// calculate total distance
float get_distance(point s ,point e) {
	return sqrt(pow(e.x - s.x, 2) + pow(e.y - s.y, 2));
}
int main()
{
	int start_point, minY = 1000000000.0;
	scanf("%d", &n);

	p = (point*)malloc(sizeof(point) * (n + 1));
	stack = (point*)malloc(sizeof(point) * (n + 1));
	
	// input point variable and check start point 
	for (int i = 1; i <= n; ++i) {
		scanf("%f %f", &p[i].x, &p[i].y);
		if (minY > p[i].y) {
			minY = p[i].y;
			start_point = i;
		}
		else if (minY == p[i].y) {
			if (p[start_point].x > p[i].x)
				start_point = i;
		}
	}
	swap(start_point);
	for (int i = 2; i <= n; ++i) 
		p[i].angle = calculate_angle(p[i]);
	sort();
	stack[0].x = 0.0;
	stack[0].y = 0.0;
	stack[0].angle = calculate_angle(stack[0]);
	graham_scan();

	sort_stack();
	for (int i = 0; i < top; ++i)
		dist += get_distance(stack[i], stack[i + 1]);
	dist += get_distance(stack[top], stack[0]);

	printf("%.2f", dist);
}

/*
1 1
-9 1
-9 -9
1 -9
1 -2
1 -4
-3 0.9
*/